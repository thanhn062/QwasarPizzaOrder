// #include "../include/pizza_order.h"
#include "../inc/clui.h"
// #ifndef STDIN_FILENO
// #define STDIN_FILENO 0
// #endif
// #define MENU_BORDER_BG_COLOR 
// #define APP_BG_COLOR
// #define SELECT_BG_COLOR
#define MENU_SIZE 26
// should I define or static all UI colors?
static struct termios old, current; //static

//TODO add mouse interactivity
// std get passwd or get input fn
void init_clui(void) {
  printf("%s", BGD_BLUE); // add on window resize mode -1 so adjust background menu_bg_color size
  terminal_control_enter_alternate_screen();
  terminal_control_clear_screen();
  printf("\e[?25l"); // hide cursor
  // printf("%s ██████╗ ██╗    ██╗ █████╗ ███████╗ █████╗ ██████╗    ██╗ ██████╗ \n██╔═══██╗██║    ██║██╔══██╗██╔════╝██╔══██╗██╔══██╗   ██║██╔═══██╗\n██║   ██║██║ █╗ ██║███████║███████╗███████║██████╔╝   ██║██║   ██║\n██║▄▄ ██║██║███╗██║██╔══██║╚════██║██╔══██║██╔══██╗   ██║██║   ██║\n╚██████╔╝╚███╔███╔╝██║  ██║███████║██║  ██║██║  ██║██╗██║╚██████╔╝\n╚══▀▀═╝  ╚══╝╚══╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝ ╚═════╝ %s", TERMINAL_CONTROL_BOLD_GREEN, TERMINAL_CONTROL_BOLD_GREEN);
}

void reset_clui(void) {
  // fgets(line, sizeof(line), stdin);
  // // write(1, ch, 1);
  // if (ch == 'q') {
  terminal_control_exit_alternate_screen();
  printf("%s", BGD_NORMAL);
  // printf("\e[?25h"); // where to place?
  terminal_control_clear_screen();
  terminal_control_move_cursor(0, 0);
  printf("\e[?25h"); // not working?
  //if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &current) != 0) {
  //   // break;
  //   return EXIT_FAILURE;
  // }
  (void) tcsetattr(STDIN_FILENO, TCSAFLUSH, &old);
}

// add are you sure you want to exit y/n
// rename Gigantic to Giant? // escap sequence bg color are strings not char
void print_cli(int cols, int rows, int mode, char* app_bg_color, char* select_bg_color, char* border_bg_color, char* menu_bg_color) { // use mouse to register input along with keys and words?
  // add ascii art Pizza Shop like Gandalf ascii (how did Gaetan made ascii art for Gandalf? is it necessarly a manual process?)
  // terminal_control_move_cursor(5, 5);
  // write(1, "\x1B[1;42m\U0001F355Welcome to the Qwasar Pizza Shop\U0001F355\x1B[1;43m\n\n", 90);
  // terminal_control_get_cols_rows(&cols, &rows);
  // terminal_control_move_cursor(5, 5);
  // write(1, "\u261e %sSmall\x1B[1;43m\t%sMedium\x1B[1;43m\t%sBig\x1B[1;43m\t%sGigantic\x1B[1;43m", 90);
  // if (mode == 0) {// comment out
  //   write(1, "\x1B[1;42m\U0001F355Welcome to the Qwasar Pizza Shop\U0001F355\x1B[1;43m\n\n", 90);
  //   terminal_control_get_cols_rows(&cols, &rows);
  //   terminal_control_move_cursor(5, 5);
  //   write(1, "\u261e \x1B[1;42mSmall\x1B[1;43m\t%sMedium\x1B[1;43m\t%sLarge\x1B[1;43m\t%sGigantic\x1B[1;43m", 90);
  // }
  // add a background shadow effect to make the menu look like it's levitating/floating
  int init_pos = 0;
  int index = 4; // menu pos
  terminal_control_clear_screen();
  terminal_control_get_cols_rows(&cols, &rows); // can I remove it?
  terminal_control_move_cursor(init_pos, rows / 2);
  // printf("%s %sWelcome to the Qwasar Pizza Shop%s %s", PIZZA, select_bg_color, app_bg_color, PIZZA); // printf doesn't behave same as write for cursor placement//\nPlease Enter what size Pizza you would like.U0001F355\x
  printf("%s %sWelcome to the %s %s %s %s %s %s Pizza Shop%s %s", PIZZA, select_bg_color, F_Q, F_W, F_A, F_S, F_A, F_R, app_bg_color, PIZZA); // printf doesn't behave same as write for cursor placement//\nPlease Enter what size Pizza you would like.U0001F355\x
  if (mode == -1) {
    terminal_control_move_cursor(index++, 6); //  \x1B[1;43m
    printf("press any key to continue..."); // welcome screen
  }
  else {
    terminal_control_move_cursor(index++, rows / 4);
    printf("%s                                                               %s", BGD_WHITE, app_bg_color);
    terminal_control_move_cursor(index++, rows / 4);
    printf("%s  %s                            MENU                           %s  %s", BGD_WHITE, menu_bg_color, BGD_WHITE, app_bg_color);
    terminal_control_move_cursor(index++, rows / 4);
    printf("%s                                                               %s", BGD_WHITE, app_bg_color);
    // terminal_control_move_cursor(index++, rows / 4); //bug
    // terminal_control_move_cursor(index++, rows / 4); //bug
    // terminal_control_move_cursor(index++, rows / 4); //bug
    terminal_control_move_cursor(index++, rows / 4); //bug
    switch (mode) {// comment out
    case 0:
      // \x1B[1;42m        \x1B[1;43m // \x1B[1;42m\x1B f        [1;43m\n
      printf("%s  %s    Small    %s %s    Medium    %s %s    Large    %s %s    Gigantic    %s  %s", BGD_WHITE, select_bg_color, BGD_WHITE, menu_bg_color, BGD_WHITE, menu_bg_color, BGD_WHITE, menu_bg_color, BGD_WHITE, app_bg_color);
      break;
    case 1:
      printf("%s  %s    Small    %s %s    Medium    %s %s    Large    %s %s    Gigantic    %s  %s", BGD_WHITE, menu_bg_color, BGD_WHITE, select_bg_color, BGD_WHITE, menu_bg_color, BGD_WHITE, menu_bg_color, BGD_WHITE, app_bg_color);
      break;  
    case 2:
      printf("%s  %s    Small    %s %s    Medium    %s %s    Large    %s %s    Gigantic    %s  %s", BGD_WHITE, menu_bg_color, BGD_WHITE, menu_bg_color, BGD_WHITE, select_bg_color, BGD_WHITE, menu_bg_color, BGD_WHITE, app_bg_color);
      break;
    case 3:
      printf("%s  %s    Small    %s %s    Medium    %s %s    Large    %s %s    Gigantic    %s  %s", BGD_WHITE, menu_bg_color, BGD_WHITE, menu_bg_color, BGD_WHITE, menu_bg_color, BGD_WHITE, select_bg_color, BGD_WHITE, app_bg_color); // is it necessary to go back go normal each time instead of just once?
      break;
    case 4:
      // terminal_control_move_cursor(index, rows / 4);
      // printf("%s  %s                                                           %s  %s", BGD_WHITE, menu_bg_color, BGD_WHITE, app_bg_color);
      // terminal_control_move_cursor(index++, rows / 4);
      printf("%s  %s Please Enter what size Pizza you would like.              %s  %s", BGD_WHITE, menu_bg_color, BGD_WHITE, app_bg_color); // toppings
      break;
    default:
      // else/default if all else, all case's do not match
      //\nPlease Enter what size Pizza you would like.
      // terminal_control_move_cursor(index++, 9);
      // printf("Please Enter what size Pizza you would like.");
      // terminal_control_move_cursor(index++, rows / 4);
      // printf("%s  %s    Small    %s %s    Medium    %s %s    Large    %s %s    Gigantic    %s  %s", BGD_WHITE, menu_bg_color, BGD_WHITE, menu_bg_color, BGD_WHITE, menu_bg_color, BGD_WHITE, menu_bg_color, BGD_WHITE, app_bg_color);
      // terminal_control_move_cursor(index++, rows / 4);
      printf("%s                                                               %s", BGD_WHITE, app_bg_color);
      while (index < MENU_SIZE) {
      terminal_control_move_cursor(index, rows / 4);
      printf("%s  %s                                                           %s  %s", BGD_WHITE, menu_bg_color, BGD_WHITE, app_bg_color);
      index += 1;
      }
      terminal_control_move_cursor(index, rows / 4);
      printf("%s                                                               %s", BGD_WHITE, app_bg_color);
      terminal_control_move_cursor(0, 0);
      // terminal_control_move_cursor(index++, rows / 4);
      // printf("%s                                                               %s", BGD_WHITE, app_bg_color);
      // while (index < MENU_SIZE) {
      //   terminal_control_move_cursor(index, rows / 4);
      //   printf("%s  %s                                                           %s  %s", BGD_WHITE, menu_bg_color, BGD_WHITE, app_bg_color);
      //   index += 1;
      // }
      // terminal_control_move_cursor(index, rows / 4);
      // printf("%s                                                               %s", BGD_WHITE, app_bg_color);
      // terminal_control_move_cursor(0, 0);
      break;
  }
}

void initTermios(int echo) {
  tcgetattr(0, &old);
  current = old;
  current.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
    current.c_lflag = current.c_lflag ^ ECHO; // vs |= ECHO
  }
  else {
    current.c_lflag &= ~ECHO; /* set no echo mode */ // vs /**/
  }
  tcsetattr(0, TCSANOW, &current);
}

void resetTermios(void) {
  tcsetattr(0, TCSANOW, &old);
}

char getch_(int echo) {
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

char getch(void) {
  return getch_(0);
}

char getche(void) {
  return getch_(1);
}

int clui() { // is clui a good name?
  // unsigned long long int size = getpagesize();
  // long long int bytes = 0;
  // char file[size + 1];
  int cols = 0;
  int rows = 0;
  int len = 100;
  int index = 0;
  char line[100] = {0};
  // int sscanf_result = 0;
  int result = -1;
  char character = '\0';
  char quit[] = "quit"; // quit vs exit
  char escp = 27; // escape sequence?
  char right[] = "\033[C";
  char left[] = "\033[D";
  char up[] = "\033[A";
  char down[] = "\033[B"; // one or more char?
  // char small[] = "small";
  // char medium[] = "medium";
  // char large[] = "large";
  // char gigantic[] = "gigantic";
  int mode = -1;
  char* answer = NULL;/* set answer to a value that falls through */
  char *menu_bg_color = NULL;
  answer = malloc(sizeof(char) * len);

  // while (index < len) {
  //   answer[index] = '\0';
  //   index += 1;
  // } // my_bzero
  // if (tcgetattr(STDIN_FILENO, &old) != 0) {
  //   // break;
  //   return EXIT_FAILURE;
  // }
  // current = old;
  // current.c_lflag = current.c_lflag ^ ECHO;
  // if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &current) != 0) {
  //   // break;
  //   return EXIT_FAILURE;
  // }
  // write(1, "\x1B[1;40m", );
  // printf("%d\t%d", cols, rows);
  // printf("%sWelcome to the Qwasar Pizza Shop%s", TERMINAL_CONTROL_BACKGROUND_RED, TERMINAL_CONTROL_NORMAL);// why printf after loop deson't work?
  // printf("%sWelcome to the Qwasar Pizza Shop", TERMINAL_CONTROL_BACKGROUND_RED);
  // how to write above result always?
  // while ((bytes = read(0, file, size)) > 0) { // how to hide and stop cursor?
  init_clui();
  print_cli(cols, rows, mode, BGD_CYAN, BGD_MAGENTA, BGD_WHITE, BGD_BLUE);
  mode = 5;
  while (1) { /*result != 0 iterate until told to move on */
    // print_cli(cols, rows, cols);
    // character = fgetc(stdin); // also take the string into account?
    character = getch(); // why no error when return value not assigned?
    // printf("%c", character);
      // if (bytes == 2) {
      // scanf("%c", *file);
    // result = my_strncmp("test", "test", 40);
    // printf("\nMenu:\n [1] Do something\n [1] Do something\nWhat do you want to do? [quit] ");
    
    // fgets(line, sizeof(line), stdin); /* read in a line */ // do my_fgets
    // line[my_strcspn(line, "\n")] = '\0';
    
    // sscanf_result = sscanf (line, "%s", answer);/* get answer */
    // strcpy(answer, line);
    // my_strncpy(answer, line, my_strlen(line));
    
    // my_strncpy(answer, line, my_strlen(line)); // a \0 needed somehwere
    // result = my_strncmp(quit, answer, my_strlen(answer));
    
    // result = my_strlen(answer);
    // result = my_strcspn(answer, "\n");
    // answer[my_strcspn(answer, "\n")] = '\0';
    // if ((sscanf_result == 0) | (sscanf_result == EOF)) {/* either a non-integer entered or an end-of-line */
    //   printf ("\n *** You have to enter an integer! ***\n");
    //   // answer = -1; /* set answer to a value that falls through */
    // }
    
    // tap twice issue
    // terminal_control_clear_screen();
    // terminal_control_move_cursor(0, 0);
    // print_cli(cols, rows, mode);

    // if (answer[0] == escp) { // remove arrow capabilities bug
    //   // return EXIT_SUCCESS;
    //   break;
    // }
    // if (my_strncmp(quit, answer, my_strlen(answer)) == 0) {
    //   // return EXIT_SUCCESS;
    //   break;
    // }
    // if (my_strncmp(left, answer, my_strlen(answer)) == 0) {
    //   if (mode == 0) {
    //     mode = 3;
    //   }
    //   else {
    //     mode -= 1;
    //   }
    // }
    // if (my_strncmp(right, answer, my_strlen(answer)) == 0) {
    //   if (mode == 3) {
    //     mode = 0;
    //   }
    //   else {
    //     mode += 1;
    //   }
    // }
    // if (mode == -1) {
      // print_cli(cols, rows, -1);
    // }
    if (mode == 5) {
      print_cli(cols, rows, 5, BGD_CYAN, BGD_MAGENTA, BGD_WHITE, BGD_BLUE);
      mode = -1;
    }
    else if (character == '\n') { // how to get the enter key and \n vs \r newline vs carriage return
      print_cli(cols, rows, 4, BGD_CYAN, BGD_MAGENTA, BGD_WHITE, BGD_BLUE);
      // getch use wait() to stop while loop etc...?
      // return EXIT_SUCCESS;
    }
    else {
      if (quit[0] == character || escp == character) {
        break;
      }
      if (left[0] == character || 'h' == character || 'l' == character) {
        if (mode == 0) {
          mode = 3;
        }
        else {
          mode -= 1;
        }
      }
      if (right[0] == character || 'j' == character || 'k' == character) {
        if (mode == 3) {
          mode = 0;
        }
        else {
          mode += 1;
        }
      }      
      print_cli(cols, rows, mode, BGD_CYAN, BGD_MAGENTA, BGD_WHITE, BGD_BLUE);
    }
    // else {
    // }

    // else {
    //   // mode += 
    // }

    // if (my_strncmp(up, answer, my_strlen(up)) == 0) {
    //   if (mode == 3) {
    //     mode = 0;
    //   }
    //   else {
    //     mode += 1;
    //   }
    // }
    // if (my_strncmp(down, answer, my_strlen(down)) == 0) {
    //   mode = 3;

    // }
    // if (my_strncmp(small, answer, my_strlen(small)) == 0) {
    //   mode = 0;
    //   printf("\n-> small\n");
    // }
    // if (my_strncmp(medium, answer, my_strlen(medium)) == 0) {
    //   mode = 1;
    //   printf("\n-> medium\n");
    // }
    // if (my_strncmp(large, answer, my_strlen(large)) == 0) {
    //   mode = 2;
    //   printf("\n-> large\n");
    // }
    // if (my_strncmp(gigantic, answer, my_strlen(gigantic)) == 0) {
    //   mode = 3;
    //   printf("\n-> gigantic\n");
    // }
    // terminal_control_clear_screen();
    // print_cli(cols, rows, mode);
    // switch (result) {
    //   case -1:
    //     printf("\nRESULT = -1\n");
    //     break;
    //   case 1:
    //     printf("\nRESULT = 1\n");
    //     break;
    //   case 0:
    //     return EXIT_SUCCESS;
    // }
    // printf("\n\"%s\"\t\"%s\"\n(%d)\n", quit, answer, result);

      // my_bzero(answer, my_strlen(answer));
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
  reset_clui();
  return EXIT_SUCCESS;
    // }
  //   if ((printf("%s%s", TERMINAL_CONTROL_BACKGROUND_YELLOW, file)) < 0) {

  //   }
    // write(1, file, bytes);
  // }
  // write(1, argv[1], 1);
// }
}

int main(int argc, char *argv[]) {
  (void)argc; (void)argv;//for now until a decode switch is implemented
  clui();
  return EXIT_SUCCESS;
}