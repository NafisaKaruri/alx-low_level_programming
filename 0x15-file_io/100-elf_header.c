#include "main.h"
/**
 * check_sys_cont - continues checking the system and prints the os/abi
 * @header: the ELF header
 */
void check_sys_cont(Elf64_Ehdr *header)
{
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_MODESTO:
			printf("Novell - Modesto\n");
			break;
		case ELFOSABI_OPENBSD:
			printf("UNIX - OpenBSD\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
			break;
	}
}

/**
 * check_sys - checks the system and prints the os/abi
 * @header: the ELF header
 */
void check_sys(Elf64_Ehdr *header)
{
	printf("  OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_AIX:
			printf("UNIX - AIX\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		default:
			check_sys_cont(header);
			break;
	}
}

/**
 * check_class - checks class and prints it
 * @header: the ELF header
 */
void check_class(Elf64_Ehdr *header)
{
	printf("  Class:                             ");
	switch (header->e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		case ELFCLASSNONE:
			printf("none\n");
			break;
	}
}

/**
 * check_entry - prints the entry point address
 * @header: the ELF header
 */
void check_entry(Elf64_Ehdr *header)
{
	int i = 0, len = 0;
	unsigned char *ptr = (unsigned char *)&header->e_entry;

	printf("  Entry point address:               0x");
	if (header->e_ident[EI_DATA] != ELFDATA2MSB)
	{
		i = header->e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!ptr[i])
			i--;
		printf("%x", ptr[i--]);
		for (; i >= 0; i--)
			printf("%02x", ptr[i]);
		printf("\n");
	}
	else
	{
		i = 0;
		len = header->e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!ptr[i])
			i++;
		printf("%x", ptr[i++]);
		for (; i <= len; i++)
			printf("%02x", ptr[i]);
		printf("\n");
	}
}

/**
 * print_elf_header - displays the information contained in the ELF
 * header at the start of an ELF FILE
 * @header: the ELF header
 */
void print_elf_header(Elf64_Ehdr *header)
{
	int j = header->e_ident[EI_DATA] == ELFDATA2MSB ? 1 : 0;
	char *p = (char *)&header->e_type;

	check_class(header);
	printf("  Data:                              ");
	if (header->e_ident[EI_DATA] == ELFDATA2LSB)
		printf("%s\n", "2's complement, little endian");
	else if (header->e_ident[EI_DATA] == ELFDATA2MSB)
		printf("%s\n", "2's complement, big endian");
	else
		printf("%s\n", "none");
	printf("  Version:                           ");
	printf("%d", header->e_ident[EI_VERSION]);
	printf("%s\n", header->e_ident[EI_VERSION] == EV_CURRENT ? " (current)" : "");
	check_sys(header);
	printf("  ABI Version:                       ");
	printf("%d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	switch (p[j])
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown>: %x\n", p[j]);
			break;
	}
	check_entry(header);
}

/**
 * main - displays the information contained in the ELF
 *	header at the start of an ELF file
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: 0 if success
 */
int main(int argc, char **argv)
{
	int fd, i;
	Elf64_Ehdr header;
	ssize_t rcount;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n"), exit(98);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]), exit(98);

	rcount = read(fd, &header, sizeof(header));
	if (rcount < 1 || rcount != sizeof(header))
		dprintf(STDERR_FILENO, "Error: Can't read from %s\n", argv[1]), exit(98);

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
	header.e_ident[EI_MAG1] != ELFMAG1 ||
	header.e_ident[EI_MAG2] != ELFMAG2 ||
	header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Not an ELF file\n");
		exit(98);
	}

	if (!(header.e_ident[0] == 0x7f && header.e_ident[1] == 'E' &&
	header.e_ident[2] == 'L' && header.e_ident[3] == 'F'))
	{
		dprintf(STDERR_FILENO, "Not an ELF file\n");
		exit(98);
	}
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%2.2x%s", header.e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");

	print_elf_header(&header);

	close(fd);

	return (0);
}
