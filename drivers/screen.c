unsigned  char  port_byte_in(unsigned  short  port) {
  // A handy C wrapper  function  that  reads a byte  from  the  specified  port
  //   "=a" (result) means: put AL  register  in  variable  RESULT  when  finished
  //   "d" (port) means: load  EDX  with  port
  unsigned  char  result;
  __asm__("in %%dx, %%al" : "=a" (result) : "d" (port ));
  return  result;
}

void  port_byte_out(unsigned  short  port , unsigned  char  data) {
  // "a" (data) means: load  EAX  with  data
  // "d" (port) means: load  EDX  with  port
  __asm__("out %%al, %%dx" : :"a" (data), "d" (port ));
}
unsigned  short  port_word_in(unsigned  short  port) {
  unsigned  short  result;
  __asm__("in %%dx, %%ax" : "=a" (result) : "d" (port ));
  return  result;
}
void  port_word_out(unsigned  short  port , unsigned  short  data) {
  __asm__("out %%ax, %%dx" : :"a" (data), "d" (port ));
}

void print_string(char * string){
  char c = string[0];
  int i = 0;
  while(c != 0x0000){
    print_char(c, i , i, WHITE_ON_BLACK);
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
  // if(col >= 0 && row >= 0){
    offset = get_screen_offset(col, row);
  // } else{
  //   // offset = get_cursor();
  // }

  // set_cursor(offset + 2);
  vidmem[offset] = character;
  vidmem[offset + 1] = attribute_byte;

}

int get_screen_offset(int col, int row){
  return ((row * MAX_COLS)  +  col ) * 2;
}


void clear_screen(){
  int i;
  unsigned char *vidmem = (unsigned char *) VIDEO_ADDRESS;
  for(i=0; i< MAX_ROWS * MAX_COLS * 2; i += 2){
    vidmem[i] = 0;
    vidmem[i+1] = 0;
  }
}


//
// int  get_cursor () {
//   // int cursor = (int) CURSOR_ADDRESS;
//   // cursor = &cursor;
//   // The  device  uses  its  control  register  as an  index
//   // to  select  its  internal  registers , of  which  we are
//   //  interested  in:
//   //    reg  14:  which  is the  high  byte of the  cursor 's offset
//   //    reg  15:  which  is the  low  byte of the  cursor 's offset
//   // Once  the  internal  register  has  been  selected , we may  read or
//   //  write a byte on the  data  register.
//   port_byte_out(REG_SCREEN_CTRL , 14);
//   int  offset = port_byte_in(REG_SCREEN_DATA) << 8;
//   port_byte_out(REG_SCREEN_CTRL , 15);
//   offset  +=  port_byte_in(REG_SCREEN_DATA);
//   //  Since  the  cursor  offset  reported  by the VGA  hardware  is the
//   //  number  of  characters , we  multiply  by two to  convert  it to
//   // a character  cell  offset.
//   return  offset;
// }
//
// void set_cursor(int offset){
//   offset /= 2;
//   port_byte_out(REG_SCREEN_CTRL, 14);e
//
//   port_byte_out(REG_SCREEN_CTRL, 15);
// }


//
//
//
// /*  Advance  the  text  cursor , scrolling  the  video  buffer  if  necessary. */
// int  handle_scrolling(int  cursor_offset) {
//   // If the  cursor  is  within  the  screen , return  it  unmodified.
//   if (cursor_offset  < MAX_ROWS*MAX_COLS *2) {
//   return  cursor_offset;
//   }
//   /*  Shuffle  the  rows  back  one. */
//   int i;
//   for (i=1; i<MAX_ROWS; i++) {
//     memory_copy(get_screen_offset (0,i) + VIDEO_ADDRESS ,
//                 get_screen_offset (0,i-1) + VIDEO_ADDRESS ,
//                 MAX_COLS *2);
//
//   }
//   /*  Blank  the  last  line by  setting  all  bytes  to 0 */
//   char* last_line = get_screen_offset (0,MAX_ROWS -1) + VIDEO_ADDRESS;
//   for (i=0; i < MAX_COLS *2; i++) {
//     last  _line[i] = 0;
//   }
//   // Move  the  offset  back  one row , such  that it is now on the  last
//   // row , rather  than  off the  edge of the  screen.
//   cursor_offset  -= 2* MAX_COLS;
//   //  Return  the  updated  cursor  position.
//   return  cursor_offset;
// }
