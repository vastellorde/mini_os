[bits 16]
[org 0x7c00]
KERNEL_OFFSET equ 0x1000

; boot drive
mov [BOOT_DRIVE], dl

; setup stack
mov bp, 0x9000
mov sp, bp

mov bx, MSG_REAL_MODE
call print
call print_nl

call load_kernel
call switch_to_pm
jmp $

%include "boot/print.asm"
%include "boot/print_hex.asm"
%include "boot/disk.asm"
%include "boot/gdt.asm"
%include "boot/32bit_print.asm"
%include "boot/switch.asm"

[bits 16]
load_kernel:
    mov bx, MSG_LOAD_KERNEL
    call print
    call print_nl

    mov bx, KERNEL_OFFSET ; destination
    mov dh, 16 ; num sectors
    mov dl, [BOOT_DRIVE] ; disk
    call disk_load
    ret

[bits 32]
BEGIN_PM:
    mov ebx, MSG_PROT_MODE
    call print_string_pm
    call KERNEL_OFFSET ; give control to ther kernel
    jmp $

BOOT_DRIVE db 0
MSG_REAL_MODE db "Started in 16-bit Real Mode", 0
MSG_PROT_MODE db "Landed in 32-bit Protected Mode", 0
MSG_LOAD_KERNEL db "Loading kernel into memory", 0

times 510 - ($-$$) db 0
dw 0xaa55
