section .data
	format db "Hello, Holberton", 10, 0
section .text
        global main
        extern printf

main:
        mov rdi, format
	xor rax, rax
        call printf
        mov eax, 0x60
        xor edi, edi
        syscall
