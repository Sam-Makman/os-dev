#include "./drivers/screen.h"

void  some_function () {
}

void  main() {
  char* video_memory = 0xb8000;
  *video_memory = 'X';
  char * test_string = "Hello World";
  print_string(test_string);
  // Call  some  function
  some_function ();
}
