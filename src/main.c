#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h> // EXIT_SUCCESS
// #include <conio.h> // first input reading approach doesn't work
// #include <cursor.h> // mouse support? look at htop

#include "../include/terminal_control.h"
#include "menu.c"
#include "user_interface.c"


int main(int argc, char *argv[]) {
  (void)argc; (void)argv;
  // https://parameshm.blogspot.com/2005/11/how-to-getor-read-arrow-key-input-in-c.html
  my_cmd_user_interface();
  return EXIT_SUCCESS;
}