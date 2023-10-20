section .data
        hello db "Hello, Holberton", 10, 0

section .text
        global main
        extern printf

main:
        mov rdi, hello
        call printf
        mov rax, 60
        xor rdi, rdi
        syscall
