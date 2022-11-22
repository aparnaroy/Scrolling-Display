#include "ncurses.h"
#include <stdio.h>
#include "scroll.h"

void openDisplay(void) {
    initscr();
    start_color();
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(GREEN, COLOR_GREEN, COLOR_GREEN);
    init_pair(RED, COLOR_RED, COLOR_RED);
}

void closeDisplay(void) {
    clearDisplay();
    refresh();
    endwin();
}

int wrap(int z) {
    if (z > 7) {
	    z = z - 8;
    }
    else if (z < 0) {
	    z = z + 8;
    }
    return z;
}

void displayLetter(char letter, int xOffset, int yOffset) {
    attron(COLOR_PAIR(color));
    if(letter == 'A') {
        // Top of letter
        mvaddch(wrap(yOffset+1),wrap(xOffset+2),'#');
        mvaddch(wrap(yOffset+1),wrap(xOffset+3),'#');
        mvaddch(wrap(yOffset+1),wrap(xOffset+4),'#');
        // Left side of letter
        mvaddch(wrap(yOffset+2),wrap(xOffset+1),'#');
        mvaddch(wrap(yOffset+3),wrap(xOffset+1),'#');
        mvaddch(wrap(yOffset+4),wrap(xOffset+1),'#');
        mvaddch(wrap(yOffset+5),wrap(xOffset+1),'#');
        mvaddch(wrap(yOffset+6),wrap(xOffset+1),'#');
        mvaddch(wrap(yOffset+7),wrap(xOffset+1),'#');
        // Right side of letter
        mvaddch(wrap(yOffset+2),wrap(xOffset+5),'#');
        mvaddch(wrap(yOffset+3),wrap(xOffset+5),'#');
        mvaddch(wrap(yOffset+4),wrap(xOffset+5),'#');
        mvaddch(wrap(yOffset+5),wrap(xOffset+5),'#');
        mvaddch(wrap(yOffset+6),wrap(xOffset+5),'#');
        mvaddch(wrap(yOffset+7),wrap(xOffset+5),'#');
        // Middle of letter
        mvaddch(wrap(yOffset+4),wrap(xOffset+2),'#');
        mvaddch(wrap(yOffset+4),wrap(xOffset+3),'#');
        mvaddch(wrap(yOffset+4),wrap(xOffset+4),'#');
    }
    else if(letter == 'R') {
        // Top of letter
        mvaddch(wrap(yOffset+1),wrap(xOffset+1),'#');
        mvaddch(wrap(yOffset+1),wrap(xOffset+2),'#');
        mvaddch(wrap(yOffset+1),wrap(xOffset+3),'#');
        mvaddch(wrap(yOffset+1),wrap(xOffset+4),'#');
        // Left side of letter
        mvaddch(wrap(yOffset+2),wrap(xOffset+1),'#');
        mvaddch(wrap(yOffset+3),wrap(xOffset+1),'#');
        mvaddch(wrap(yOffset+4),wrap(xOffset+1),'#');
        mvaddch(wrap(yOffset+5),wrap(xOffset+1),'#');
        mvaddch(wrap(yOffset+6),wrap(xOffset+1),'#');
        mvaddch(wrap(yOffset+7),wrap(xOffset+1),'#');
        // Right side of letter
        mvaddch(wrap(yOffset+2),wrap(xOffset+5),'#');
        mvaddch(wrap(yOffset+3),wrap(xOffset+5),'#');
        // Middle of letter
        mvaddch(wrap(yOffset+4),wrap(xOffset+2),'#');
        mvaddch(wrap(yOffset+4),wrap(xOffset+3),'#');
        mvaddch(wrap(yOffset+4),wrap(xOffset+4),'#');
        // Rest of letter
        mvaddch(wrap(yOffset+5),wrap(xOffset+3),'#');
        mvaddch(wrap(yOffset+6),wrap(xOffset+4),'#');
        mvaddch(wrap(yOffset+7),wrap(xOffset+5),'#');
    }
    move(0,10);
    refresh();
}

void clearDisplay(void) {
    attron(COLOR_PAIR(4));
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            mvaddch(i, j, '#');
        }
    }
}
