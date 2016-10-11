; A bootsector that prints a string using a function

;tells the assembler where the code will be loaded
[org 0x7c00]

  mov bx, HELLO_MSG ;pass message in bx register
  call print_string ;call print string function

  mov bx, GOODBYE_MSG ;load goodby message in bx register
  call print_string ; call print_string

  mov dx, 0xFEC2
  call print_hex
  jmp $ ;Hang

  %include "print_string.asm"
  %include "print_hex.asm"

  ;DATA
  HELLO_MSG:
    db 'Hello World', 0   ;0 is our string terminator value

  GOODBYE_MSG:
    db "Goodbye!", 0


;This creates the bootsector, padding it with zero's
times 510-($-$$) db 0

dw 0xaa55
