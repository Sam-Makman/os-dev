[bits 32]
;define constants
VIDEO_MEMORY equ 0xb8000
WHITE_ON_BLACK equ 0x0f

;prints a null terminated string pointed to by ebx
;ebx points to string
;edx points to video memory

print_string_pm:
  pusha
  mov edx, VIDEO_MEMORY ; set EDX to start of video memory

  print_string_pm_loop:
    mov al, [ebx] ;
    mov ah, WHITE_ON_BLACK

    cmp al, 0
    je done

    mov [edx], ax

    add ebx, 1 ; point to next character in ebx
    add edx, 2 ; next space in video memory to place character

    jmp print_string_pm_loop


  print_string_pm_done:
  popa
  ret
