#include "../include/pizza_order.h"

int my_cmd_user_interface() {
  unsigned long long int size = getpagesize();
  long long int bytes = 0;
  char file[size + 1];
  int cols = 0;
  int rows = 0;
  // char ch = 'q';
  int len = 100;
  int index = 0;
  char line[100] = {0};
  int sscanf_result = 0;
  int result = -1;
  char quit[] = "quit";
  char* answer = NULL;/* set answer to a value that falls through */
  answer = malloc (sizeof(char) * len);

  while (index < len) {
    answer[index] = '\0';
    index += 1;
  }
  printf("%s", TERMINAL_CONTROL_BACKGROUND_YELLOW);
  terminal_control_enter_alternate_screen();
  terminal_control_clear_screen();
  terminal_control_get_cols_rows(&cols, &rows);
  terminal_control_move_cursor(5, 5);
  write(1, "\x1B[1;42m\U0001F355Welcome to the Qwasar Pizza Shop\U0001F355\x1B[1;43m\n\n", 90); //\nPlease Enter what size Pizza you would like.
  terminal_control_get_cols_rows(&cols, &rows);
  terminal_control_move_cursor(5, 5);
  write(1, "\u261e \x1B[1;41mSmall\x1B[1;43m\t\x1B[1;41mMedium\x1B[1;43m\t\x1B[1;41mBig\x1B[1;43m\t\x1B[1;41mGigantic\x1B[1;43m", 90);
  // write(1, "\x1B[1;40m", );
  // printf("%d\t%d", cols, rows);
  // printf("%sWelcome to the Qwasar Pizza Shop%s", TERMINAL_CONTROL_BACKGROUND_RED, TERMINAL_CONTROL_NORMAL);// why printf after loop deson't work?
  // printf("%sWelcome to the Qwasar Pizza Shop", TERMINAL_CONTROL_BACKGROUND_RED);

  // while ((bytes = read(0, file, size)) > 0) { // how to hide and stop cursor?
  
  while (result != 0) { /* iterate until told to move on */  
      // if (bytes == 2) {
      // scanf("%c", *file);
    // result = my_strncmp("test", "test", 40);
    printf ("\nMenu:\n");
    // printf (" [1] Do something");
    // printf (" [2] Do something else");
    printf ("\nWhat do you want to do? [quit] ");
    fgets (line, sizeof(line), stdin); /* read in a line */
    // sscanf_result = sscanf (line, "%s", answer);/* get answer */
    strcpy(answer, line);
    result = my_strncmp(quit, answer, len);
    // result = my_strlen(answer);

    if ((sscanf_result == 0) | (sscanf_result == EOF)) {/* either a non-integer entered or an end-of-line */
      printf ("\n *** You have to enter an integer! ***\n");
      // answer = -1; /* set answer to a value that falls through */
    }
    terminal_control_clear_screen();
    terminal_control_move_cursor(0, 0);
        printf("%s\t%s\n", quit, answer);
    printf("%d\n", result);
  //   switch (answer) {
  //     case 0:
  //       break;
  //     case 1:
  //       printf (" Doing something ... ");
  //       break;
  //     case 2:
  //       printf (" Doing something else ... ");
  //       break;
  //     default: /* keep going if answer is not 0, 1, or 2 */
  //       break;
  //   }
  }
    // fgets(line, sizeof(line), stdin);
    // // write(1, ch, 1);
    // if (ch == 'q') {
      terminal_control_exit_alternate_screen();
      printf("%s", TERMINAL_CONTROL_BACKGROUND_NORMAL);
      terminal_control_clear_screen();
      terminal_control_move_cursor(0, 0);
      return EXIT_SUCCESS;
    // }
  //   if ((printf("%s%s", TERMINAL_CONTROL_BACKGROUND_YELLOW, file)) < 0) {

  //   }
    // write(1, file, bytes);
  // }
  // write(1, argv[1], 1);
// }

}