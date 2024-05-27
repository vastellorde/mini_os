disk_load:
    pusha

    push dx

    mov ah, 0x02 ; mode
    mov al, dh ; read dh number of sectors
    mov cl, 0x02 ; start from sector 2(1 is boot sector)
    mov ch, 0x00 ; cylinder
    mov dh, 0x00 ; head
    int 0x13 ; bios interrup
    jc disk_error

    pop dx
    cmp al, dh
    jne sectors_error
    popa
    ret

disk_error:
    mov bx, DISK_ERROR
    call print
    call print_nl
    mov dh, ah
    call print_hex
    jmp disk_loop

sectors_error:
    mov bx, SECTORS_ERROR
    call print

disk_loop:
    jmp $

DISK_ERROR: db "Disk read error", 0
SECTORS_ERROR: db "Incorrect number of sectors read", 0
