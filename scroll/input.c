#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>

void openInput(void) {
    noecho();
    cbreak();
    keypad(stdscr,TRUE);
    nodelay(stdscr,TRUE);
}

void closeInput(void) {
    int i = 0;
}

int checkInput(int delay) {
    int ch = getch();
    if('\n' == ch || '\r' == ch || KEY_ENTER == ch)
    {
        return 5;
    } else if(KEY_LEFT == ch) {
        return 1;
    } else if(KEY_RIGHT == ch) {
        return 2;
    } else if(KEY_UP == ch) {
        return 3;
    } else if(KEY_DOWN == ch) {
        return 4;
    }
    usleep(delay);
    return 0;
}
