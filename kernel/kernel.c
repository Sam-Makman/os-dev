#include "../drivers/screen.h"
#include "../drivers/screen.c"
#include "../drivers/ports.h"
#include "../drivers/ports.c"
#include "util.h"
#include "util.c"

void  some_function () {
}

void  main() {
  char* video_memory = 0xb8000;
  *video_memory = 'X';
  char * test_string = "abcdefghijklmpnoqrstuvwxyzaabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz1234567891011121314151617181920212223242526272829";
  // clear_screen();
  kprint(test_string);
  kprint_at(test_string, 80, 25);
  kprint_at(test_string, 80, 25);
  kprint_at(test_string, 80, 25);
  // print_string("abcdefghijkl");
  // Call  some  function
  some_function ();
}
