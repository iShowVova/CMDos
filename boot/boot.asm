; new version of bootloader code
; boot.asm
[org 0x7C00]
start:
    mov si, hello
    call print_string
    jmp $

print_string:
    lodsb
    or al, al
    jz done
    mov ah, 0x0E
    int 0x10
    jmp print_string
done:
    ret

hello db 'Hello, OS!', 0

times 510 - ($ - $$) db 0
dw 0xAA55