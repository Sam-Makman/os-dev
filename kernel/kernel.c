void  some_function () {
}

void  main() {
  char* video_memory = 0xb8000;
  *video_memory = 'X';
  // Call  some  function
  some_function ();
}
