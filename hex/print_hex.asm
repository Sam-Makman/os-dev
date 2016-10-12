print_hex:
  pusha ;push registers to stack
  mov bx, HEX_OUT ;location of hex string format to bx
  add bx, 1 ; add 1 to location to skip first value of string

  mov cl, dh ; move high byte to cl reg
  shr cl, 4 ; shift right 4 bits
  call add_to ; go to add_to

  mov cl, dh ; move high byte to cl reg
  sal cl, 4 ; shitf left
  shr cl, 4 ; shift right, this clears high bits
  call add_to

  mov cl, dl
  shr cl, 4
  call add_to

  mov al, dl
  sal cl, 4
  shr cl, 4
  call add_to

  mov bx, HEX_OUT
  call print_string
  popa
  ret




  add_to:
    cmp cl, 9 ; compare cl to 9
    jg high ;jump to high if cl is greater than 9
      add cl, 0x30 ; add 0x30 if cl is less than or equal to 9
      jmp end ; jump to The end
    high:
      add cl, 0x37 ; add 0x37 if cl is greater than 9 i.e. letter part of hex
    end:
    add bx, 1 ; add to bx memory address
    mov [bx], cl ; put value in cl at location bx points to
    ret


HEX_OUT:
  db '0x0000', 0
