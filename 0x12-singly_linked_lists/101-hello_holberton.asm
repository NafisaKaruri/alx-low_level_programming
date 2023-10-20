section .data
	hello db "Hello, Holberton", 10, 0

section .text
	global main
	extern printf

main:
	mov rdi, hello ; the string to print
	xor al, al     ; number of vectors used for argumuments	
	call printf    ; call printf
	mov eax, 60    ; system call number for exit
	xor edi, edi   ; exit code
	syscall        ; make system call
