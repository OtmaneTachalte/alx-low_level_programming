section .data
    hello db "Hello, Holberton", 0x0A, 0 ; The string to be printed with a newline and null terminator

section .text
    extern printf
    global main

main:
    ; Prepare the stack to be aligned
    push rbp

    ; Prepare arguments for printf
    mov rdi, hello      ; The format string (1st argument of printf)

    ; Call printf
    call printf

    ; Clean up the stack
    pop rbp

    ; Exit the program
    mov rax, 60         ; syscall: exit
    xor rdi, rdi        ; status: 0
    syscall
