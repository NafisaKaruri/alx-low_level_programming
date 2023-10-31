#include "main.h"

/**
 * check_sys - checks the system and prints the os/abi
 * @header: the ELF header
 */
void check_sys(Elf64_Ehdr *header)
{
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case 53:
			printf("<unknown: 53>\n");
			break;
		default:
			printf("Other\n");
	}
}
/**
 * print_elf_header - displays the information contained in the ELF
 * header at the start of an ELF FILE
 * @header: the ELF header
 */
void print_elf_header(Elf64_Ehdr *header)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n  Class:                             ");
	printf("%s\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("  Data:                              ");
	if (header->e_ident[EI_DATA] == ELFDATA2LSB)
		printf("%s\n", "2's complement, little endian");
	else
		printf("%s\n", "2's complement, big endian");
	printf("  Version:                           ");
	printf("%d (current)\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            ");
	check_sys(header);
	printf("  ABI Version:                       ");
	printf("%d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	switch (header->e_type)
	{
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		default:
			printf("Other\n");

	}
	printf("  Entry point address:               ");
	printf("0x%lx\n", header->e_entry);
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
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n"), exit(98);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]), exit(98);

	if (lseek(fd, 0, SEEK_SET) == -1)
		dprintf(STDERR_FILENO, "Error: seeking in file"), exit(98);

	if (read(fd, &header, sizeof(header)) != sizeof(header))
		dprintf(STDERR_FILENO, "Error: Can't read from %s\n", argv[1]), exit(98);

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
	header.e_ident[EI_MAG1] != ELFMAG1 ||
	header.e_ident[EI_MAG2] != ELFMAG2 ||
	header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Not an ELF file\n");
		exit(98);
	}

	print_elf_header(&header);

	close(fd);

	return (0);
}
