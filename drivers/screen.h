#ifndef SCREEN
#define SCREEN


#define  VIDEO_ADDRESS 0xb8000
#define CURSOR_ADDRESS 0xb87D0
#define  MAX_ROWS  25
#define  MAX_COLS  80

//  Attribute  byte  for  our  default  colour  scheme.
#define  WHITE_ON_BLACK 0x0f

//  Screen  device I/O ports
#define  REG_SCREEN_CTRL 0x3D4
#define  REG_SCREEN_DATA 0x3D5

void print_string(char * string);

void print_char(char  character , int col , int row , char  attribute_byte);

int get_screen_offset(int col, int row);

int get_cursor();

int handle_scrolling(int cursor_offset);

void set_cursor(int offest);

void clear_screen();

#endif
