#ifndef MY_TC_H
#define MY_TC_H

#include <asm-generic/ioctls.h>
#include <stdio.h>
#include <sys/ioctl.h> //implement my own
#include <termios.h>
#include <unistd.h>

/* below define standard preset escape seq */
#define TC_NRM  "\x1b[0m" // vs \033[0m? vs x1b/B vs other less chars?
#define TC_BLA  "\x1b[1;30m"
#define TC_RED  "\x1b[1;31m"
#define TC_GRN  "\x1b[1;32m"
#define TC_YEL  "\x1b[1;33m"
#define TC_BLU  "\x1b[1;34m"
#define TC_MAG  "\x1b[1;35m"
#define TC_CYN  "\x1b[1;36m"
#define TC_WHT  "\x1b[1;37m"

#define TC_BNRM "\x1B[0m"
#define TC_BRED "\x1B[0;31m"
#define TC_BGRN "\x1B[0;32m"
#define TC_BYEL "\x1B[0;33m"
#define TC_BBLU "\x1B[0;34m"
#define TC_BMAG "\x1B[0;35m"
#define TC_BCYN "\x1B[0;36m"
#define TC_BWHT "\x1B[0;37m"

#define TC_BGNRM "\x1B[40m"
#define TC_BGRED "\x1B[41m" //" \x1B[41m" spaces matter?
#define TC_BGGRN "\x1B[42m"
#define TC_BGYEL "\x1B[43m"
#define TC_BGBLU "\x1B[44m"
#define TC_BGMAG "\x1B[45m"
#define TC_BGCYN "\x1B[46m"
#define TC_BGWHT "\x1B[47m"
// 'TC_BGMAG' macro redefinedclang(-Wmacro-redefined)
// my_tc.h(33, 9): Previous definition is here
#define TC_BRNRM "\x1B[90m" //bright black is gray
#define TC_BRRED "\x1B[91m"
#define TC_BRGRN "\x1B[92m"
#define TC_BRYEL "\x1B[93m"
#define TC_BRBLU "\x1B[94m"
#define TC_BRMAG "\x1B[95m"
#define TC_BRCYN "\x1B[96m"
#define TC_BRWHT "\x1B[97m"
// to remember those ^^ order is bla0,red1,grn2,yel3,blu4,mag5,cyan6,wht7

//#define tc_clear_screen() puts("\x1B[2J")
//improved clear screen
#define tc_clear_screen() write(1, "\033[H\033[2J\033[3J", 11)
#define tc_move_cursor(X, Y) printf("\033[%d;%dH", Y, X)

void tc_get_cols_rows(int *cols, int *rows);

#define tc_enter_alt_screen() puts("\033[?1049h\033[H")
#define tc_exit_alt_screen() puts("\033[?1049l")

void tc_echo_off();
void tc_echo_on();
//defining functions below probably bad?
void tc_get_cols_rows(int *cols, int *rows){
    struct winsize size;
    ioctl(1, TIOCGWINSZ, &size);
    *cols = size.ws_col;
    *rows = size.ws_row;
}//tc_get_cols_rows*/

void tc_echo_off(){
    struct termios term;
    tcgetattr(1, &term);
    term.c_lflag &= ~ECHO;
    tcsetattr(1, TCSANOW, &term);
}//tc_echo_off*/

void tc_echo_on(){
    struct termios term;
    tcgetattr(1, &term);
    term.c_lflag |= ECHO;
    tcsetattr(1, TCSANOW, &term);
}//tc_echo_on*/

#endif /* MY_TC_H */

/*
#ifndef TERMINAL_CONTROL_HEADER
#define TERMINAL_CONTROL_HEADER

// what is default c header for this kind of functions is it ioctl.h? if so recode mind, if not find a lib that do it and copy/fork it + find a better define name convention to use like the stdint typedef
#include <sys/ioctl.h>
#include "./my_unicode/my_fancy_letters.h"
// https://unicode-table.com/
// https://youtu.be/WcN7ryZYUeQ?feature=shared
*/
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

/*
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

#define BGD_NORMAL  "\x1B[1;40m"
#define BGD_RED     "\x1B[1;41m"
#define BGD_GREEN   "\x1B[1;42m"
#define BGD_YELLOW  "\x1B[1;43m"
#define BGD_BLUE    "\x1B[1;44m"
#define BGD_MAGENTA "\x1B[1;45m"
#define BGD_CYAN    "\x1B[1;46m"
#define BGD_WHITE   "\x1B[1;47m"

#define terminal_control_clear_screen() puts("\x1B[2J")

#define terminal_control_move_cursor(X, Y) printf("\033[%d;%dH", X, Y)

#define terminal_control_enter_alternate_screen() puts("\033[?1049h\033[H")
#define terminal_control_exit_alternate_screen() puts("\033[?1049l")

void terminal_control_get_cols_rows(int *cols, int *rows) {
    struct winsize size;
    ioctl(1, TIOCGWINSZ, &size);
    *cols = size.ws_col;
    *rows = size.ws_row;
}

#endif
*/
// my unicode define naming convmentiopn with U
// Old style english alphabet (fancy letters)
#define F_A "\U0001D56C"
#define F_B "\U0001D56D"
#define F_C "\U0001D56E"
#define F_D "\U0001D56F"
#define F_E "\U0001D570"
#define F_F "\U0001D571"
#define F_G "\U0001D572"
#define F_H "\U0001D573"
#define F_I "\U0001D574"
#define F_J "\U0001D575"
#define F_K "\U0001D576"
#define F_L "\U0001D577"
#define F_M "\U0001D578"
#define F_N "\U0001D579"
#define F_O "\U0001D57A"
#define F_P "\U0001D57B"
#define F_Q "\U0001D57C"
#define F_R "\U0001D57D"
#define F_S "\U0001D57E"
#define F_T "\U0001D57F"
#define F_U "\U0001D580"
#define F_V "\U0001D581"
#define F_W "\U0001D582"
#define F_X "\U0001D583"
#define F_Y "\U0001D584"
#define F_Z "\U0001D585"
// TODO add box drawing unicode char like qwasar gandalf name output

// my block elements.h
#define FULL_BLOCK "\U00002588"
/*
#ifndef TERMINAL_CONTROL_HEADER
#define TERMINAL_CONTROL_HEADER

#include <sys/ioctl.h>

#define CRY         "\U0001F622"
#define EXPLODE     "\U0001F4A5"
#define FLEX        "\U0001F4AA"
#define IMP         "\U0001F608"
#define KNIFE       "\U0001F52A"
#define LIT         "\U0001F525"

#define EOC         "\033[0m"
#define BLACK       "\033[0;30m"
#define RED         "\033[0;31m"
#define GREEN       "\033[0;32m"

#define GREY        "\033[1;30m"
#define LAVENDER    "\033[1;35m"
#define CYAN        "\033[1;36m"
#define WHITE       "\033[1;37m"
#define UNDERLINE   "\033[4m"

#define TERMINAL_CONTROL_NORMAL             "\x1B[0m"
#define TERMINAL_CONTROL_BLACK              "\x1B[0;30m"
#define TERMINAL_CONTROL_RED                "\x1B[0;31m"
#define TERMINAL_CONTROL_GREEN              "\x1B[0;32m"
#define TERMINAL_CONTROL_YELLOW             "\x1B[0;33m"

#define TERMINAL_CONTROL_BOLD_NORMAL        "\x1B[0m"
#define TERMINAL_CONTROL_BOLD_RED           "\x1B[0;31m"
#define TERMINAL_CONTROL_BOLD_GREEN         "\x1B[0;32m"
#define TERMINAL_CONTROL_BOLD_YELLOW        "\x1B[0;33m"

#define TERMINAL_CONTROL_BACKGROUND_NORMAL  "\x1B[1;40m"
#define TERMINAL_CONTROL_BACKGROUND_RED     "\x1B[1;41m"
#define TERMINAL_CONTROL_BACKGROUND_GREEN   "\x1B[1;42m"

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

*/