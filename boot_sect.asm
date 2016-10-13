[org 0x7c00]

    mov [BOOT_DRIVE], dl ; BIOS stores out boot drive in dl,
                         ; store this value so we don't lose it

    mov bp, 0x8000 ; this is the start of our stack, way out of the way
    mov sp, bp      ; set stack pointer to base of the stack

    mov bx, 0x9000 ; load 5 sectors 0x0000 (ES) to 0x9000 (BX)
    mov dh, 5       ; from boot disk
    mov dl, [BOOT_DRIVE]
    call disk_load

    mov dx, [0x9000] ; print the first loaded work, which
    call print_hex ; we expect to be 0xdada. Stored at 0x9000

    mov dx, [0x9000 + 512] ; print the first word from the second sector
    call print_hex ; we expect 0xface

    jmp $

    %include "./print/print_string.asm"
    %include "./hex/print_hex.asm"
    %include "disk_load.asm"


    ;Global Variables
    BOOT_DRIVE db 0

    ;bootsector padding
    times 510-($-$$) db 0
    dw 0xaa55

;We know  that  BIOS  will  load  only  the  first 512-byte  sector  from  the disk ,
; so if we  purposely  add a few  more  sectors  to our  code by  repeating  some
; familiar  numbers , we can  prove  to  ourselfs  that we  actually  loaded  those
; additional  two  sectors  from  the  disk we  booted  from.
times  256 dw 0xDADA
times  256 dw 0xFACE
