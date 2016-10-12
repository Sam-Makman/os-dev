print_string:
  pusha ;push all registers so they can be restored
  mov ah, 0x0e ;Still not 100% sure why this is nessisary

  begin_loop: ;begining of loop
    mov al, [bx] ;move the value at bx into al
    int 0x10 ;interupt and print
    add bx, 1 ;add 1 to bx, this increments the memory address by 1 byte

    cmp al, 0x00 ;compare the value at al to the null terminator
    jne begin_loop ;go to begining of loop if not end of string
  popa ;restore stack
  ret ;return 
