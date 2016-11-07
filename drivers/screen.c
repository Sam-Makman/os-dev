#include <sys/io.h>

int cursor_position;

void print_string(char * string){
  char c = string[0];
  int i = 0;
  while(c != 0x0000){
    print_char(c, -1 , -1, WHITE_ON_BLACK);
    i++;
    c = string[i];
  }
}

void print_char(char character, int col, int row, char attribute_byte){
  //get location of video memory
  unsigned char *vidmem = (unsigned char *) VIDEO_ADDRESS;

  // if no custom color use white on black
  if(! attribute_byte){
    attribute_byte = WHITE_ON_BLACK;
  }

  int offset;
  if(col >= 0 && row >= 0){
    offset = get_screen_offset(col, row);
    cursor_position = offset/2;
  } else{
    offset = cursor_position * 2;
    cursor_position++;
  }
  set_cursor(offset);
  vidmem[offset] = character;
  vidmem[offset + 1] = attribute_byte;

}

int get_screen_offset(int col, int row){
  return ((row * MAX_COLS)  +  col ) * 2;
}


void clear_screen(){
  int i;
  unsigned char *vidmem = (unsigned char *) VIDEO_ADDRESS;
  for(i=0; i < MAX_ROWS * MAX_COLS * 2; i += 2){
    vidmem[i] = 0;
    vidmem[i+1] = 0;
  }
}


void set_cursor(int offset){
   offset /= 2;

   // cursor LOW port to vga INDEX register
   outb(REG_SCREEN_CTRL, 14);
   outb(REG_SCREEN_DATA, (unsigned char)(offset&0xFF));
  //  // cursor HIGH port to vga INDEX register
   outb(REG_SCREEN_CTRL, 15);
   outb(REG_SCREEN_DATA, (unsigned char )((offset>>8)&0xFF));
}
