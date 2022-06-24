#ifndef TERMINAL_CONTROL_HEADER
#define TERMINAL_CONTROL_HEADER

#include <sys/ioctl.h>

#define HUNDRED     "\U0001F4AF"
#define BLESS       "\U0001F64F"
#define BLUSH       "\U0001F60A"
#define BOMB        "\U0001F4A3"
#define COFFEE      "\U00002615"
#define CREEP       "\U0001F31D"
#define CRY         "\U0001F622"
#define EXPLODE     "\U0001F4A5"
#define FLEX        "\U0001F4AA"
#define IMP         "\U0001F608"
#define KNIFE       "\U0001F52A"
#define LIT         "\U0001F525"
#define LOL         "\U0001F602"
#define LOVE        "\U0001F60D"
#define MONEY       "\U0001f4B0"
#define OKAY        "\U0001F44C"
#define PARTY       "\U0001F38A"
#define POOP        "\U0001F4A9"
#define RESPEKT     "\U0000270A"
#define SCREAM      "\U0001F631"
#define SWEAT       "\U0001F4A6"
#define SMIRK       "\U0001F60F"
#define SOB         "\U0001F62D"
#define SLEEPY      "\U0001F62A"
#define TADA        "\U0001F389"
#define UMMM        "\U0001F605"
#define WINK        "\U0001F609"
#define WEARY       "\U0001F629"
#define PIZZA       "\U0001F355"
#define ZZZ         "\U0001F4A4"
#define UNAMUSED    "\U0001F612"
l

#define EOC         "\033[0m"
#define BLACK       "\033[0;30m"
#define RED         "\033[0;31m"
#define GREEN       "\033[0;32m"
#define DARKYELLOW  "\033[0;33m"
#define BLUE        "\033[0;34m"
#define MAGENTA     "\033[0;35m"
#define LIGHTBLUE   "\033[0;36m"
#define LIGHTGREY   "\033[0;37m"

#define GREY        "\033[1;30m"
#define PINK        "\033[1;31m"
#define LIME        "\033[1;32m"
#define YELLOW      "\033[1;33m"
#define LAVENDER    "\033[1;35m"
#define CYAN        "\033[1;36m"
#define WHITE       "\033[1;37m"
#define UNDERLINE   "\033[4m"

#define TERMINAL_CONTROL_NORMAL             "\x1B[0m"
#define TERMINAL_CONTROL_BLACK              "\x1B[0;30m"
#define TERMINAL_CONTROL_RED                "\x1B[0;31m"
#define TERMINAL_CONTROL_GREEN              "\x1B[0;32m"
#define TERMINAL_CONTROL_YELLOW             "\x1B[0;33m"
#define TERMINAL_CONTROL_BLUE               "\x1B[0;34m"
#define TERMINAL_CONTROL_MAGENTA            "\x1B[0;35m"
#define TERMINAL_CONTROL_CYAN               "\x1B[0;36m"
#define TERMINAL_CONTROL_WHITE              "\x1B[0;37m"

#define TERMINAL_CONTROL_BOLD_NORMAL        "\x1B[0m"
#define TERMINAL_CONTROL_BOLD_RED           "\x1B[0;31m"
#define TERMINAL_CONTROL_BOLD_GREEN         "\x1B[0;32m"
#define TERMINAL_CONTROL_BOLD_YELLOW        "\x1B[0;33m"
#define TERMINAL_CONTROL_BOLD_BLUE          "\x1B[0;34m"
#define TERMINAL_CONTROL_BOLD_MAGENTA       "\x1B[0;35m"
#define TERMINAL_CONTROL_BOLD_CYAN          "\x1B[0;36m"
#define TERMINAL_CONTROL_BOLD_WHITE         "\x1B[0;37m"

#define TERMINAL_CONTROL_BACKGROUND_NORMAL  "\x1B[1;40m"
#define TERMINAL_CONTROL_BACKGROUND_RED     "\x1B[1;41m"
#define TERMINAL_CONTROL_BACKGROUND_GREEN   "\x1B[1;42m"
#define TERMINAL_CONTROL_BACKGROUND_YELLOW  "\x1B[1;43m"
#define TERMINAL_CONTROL_BACKGROUND_BLUE    "\x1B[1;44m"
#define TERMINAL_CONTROL_BACKGROUND_MAGENTA "\x1B[1;45m"
#define TERMINAL_CONTROL_BACKGROUND_CYAN    "\x1B[1;46m"
#define TERMINAL_CONTROL_BACKGROUND_WHITE   "\x1B[1;47m"

#define terminal_control_clear_screen() puts("\x1B[2J")

#define terminal_control_move_cursor(X, Y) printf("\033[%d;%dH", X, Y)

void terminal_control_get_cols_rows(int* cols, int *rows);
#define terminal_control_enter_alternate_screen() puts("\033[?1049h\033[H")
#define terminal_control_exit_alternate_screen() puts("\033[?1049l")

void terminal_control_get_cols_rows(int* cols, int* rows) {
    struct winsize size;
    ioctl(1, TIOCGWINSZ, &size);
    *cols = size.ws_col;
    *rows = size.ws_row;
}

#endif