#include "../drivers/screen.h"
#include "../drivers/screen.c"

void  some_function () {
}

void  main() {
  char* video_memory = 0xb8000;
  *video_memory = 'X';
  char * test_string = "abcdefghijklmpnoqrstuvwxyzaabbccddeeffgghhiijjkkllmmnnoopp\nqqrrssttuuvvwwxxyyzz1234567891011121314151617181920212223242526272829";
  // clear_screen();
  print_string(test_string);
  // print_string("abcdefghijkl");
  // Call  some  function
  some_function ();
}
