disk_load:
  push dx ;dx tells us how many sectors we should read

  mov ah, 0x02 ;BIOS read sector function
  mov al, dh   ; read dh sectors
  mov ch, 0x00 ; Select cylinder 0
  mov dh, 0x00 ; Select head 0
  mov cl, 0x02 ; start reading from the second sector,
               ; the sector after the boot sector

  int 0x13 ; BIOS interupt

  jc disk_error ; jump if carry flag is set (Error)

  pop dx ; restore dx from the stack
  cmp dh, al ; if AL (sector read) does not equal DH (Sector expected )
  jne disk_error ;show error message
  ret

disk_error:

  mov bx, DISK_ERROR_MSG
  call print_string
  jmp $

; Global Variabls
DISK_ERROR_MSG  db "Disk Read Error!", 0
