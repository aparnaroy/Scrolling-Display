#include "scroll.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "ncurses.h"

void handler(unsigned int code);

int main(int argc, char **argv) {
    int count = 0;
    float x = 0.0;
    float y = 0.0;
    int mode = 0;
    int key = 6;
    int prev = 6;
    int temp = 0;
    float xspeed = 1.0;
    float yspeed = 1.0;
    
    int help = 0;
    int argument = 0;
    int nskip = 0;
    int validarg = 0;
    
    for (int i=0; i < argc; i++) {
        if(strcmp(argv[i], "-h") == 0) {
            help = 1;
            validarg = 1;
        }
        else if ((strcmp(argv[i], "white") == 0) && (strcmp(argv[i-1], "-c") == 0)) {
            argument = 2;
            validarg = 1;
        }
        else if ((strcmp(argv[i], "red") == 0) && (strcmp(argv[i-1], "-c") == 0)) {
            argument = 3;
            validarg = 1;
        }
        else if ((strcmp(argv[i], "green") == 0) && (strcmp(argv[i-1], "-c") == 0)) {
            argument = 4;
            validarg = 1;
        }
        else if ((strcmp(argv[i], "blue") == 0) && (strcmp(argv[i-1], "-c") == 0)) {
            argument = 5;
            validarg = 1;
        }
        else if (strcmp(argv[i], "-nskip") == 0) {
            nskip = 6;
            validarg = 1;
        }
        else if (argc == 1 && (strcmp(argv[0], "./scroll") == 0)) {
            validarg = 1;
        }
        else {
            validarg = 2;
        }
    }
    

    color = 1;
    
    if (nskip == 6) {
        printf("You gave %d arguments.\n", argc);
        mode = 1;
    }

    if (help == 1 || validarg == 2) {
        printf("Your first argument was: %s. To run the program type make, hit ENTER, and then type ./scroll.\nYou will be able to use the arrow keys to move a letter around, and then after hitting ENTER, will be able to do the same with another letter.\nPressing ENTER a third time will exit from the program.\n\nUse the -c COLOR argument, where COLOR can be white, red, green, or blue, to set the scrolling display color to the given color.\nUse the -nskip argument to skip directly to the second letter and then see the number of command-line arguments you passed.\n", argv[0]);
        exit(0);
        //mode = 3;
    }

    if (argument == 2) {
        color = 1;
    }
    else if (argument == 3) {
        color = 2;
    }
    else if (argument == 4) {
        color = 3;
    }
    else if (argument == 5) {
        color = 5;
    }

    openDisplay();
    openInput();

    while(mode == 0) {
        temp = checkInput(1000);
        if ((temp == 1 || temp == 2) && (temp == key)) {
            xspeed = xspeed + 1;
            if (xspeed >= 10) {
                xspeed = 10;
            }
        }
        else if ((temp == 3 || temp == 4) && (temp == key)) {
            yspeed = yspeed + 1;
            if (yspeed >= 10) {
                yspeed = 10;
            }
        }
        else if ((temp == 1 && key == 2) || (temp == 2 && key == 1)) {
            xspeed = xspeed - 1;
            if (xspeed < 0) {
                xspeed = 1;
            }
            else if (xspeed == 0) {
                key = 6;
            }
        }
        else if ((temp == 3 && key == 4) || (temp == 4 && key == 3)) {
            yspeed = yspeed - 1;
            if (yspeed < 0) {
                yspeed = 1;
            }
            else if (yspeed == 0) {
                key = 6;
            }
        }
        else if (temp != 0) {
            prev = key;
            key = temp;
        }
        
        if (key == 1 || prev == 1) {
            x = x - (xspeed * .001);
            if(x<0) {
                x=7;
            }
        }
        if (key == 2 || prev == 2) {
            x = x + (xspeed * .001);
            if(x>7) {
                x=0;
            }
        }
        if (key == 3 || prev == 3) {
            y = y - (yspeed * .001);
            if(y<0) {
                y=7;
            }
        }
        if (key == 4 || prev == 4) {
            y = y + (yspeed * .001);
            if(y>7) {
                y=0;
            }
        }
        if (key == 5) {
            mode = mode + 1;
        }
        
        clearDisplay();
        count++;
        if(count == 1000) {
            clearDisplay();
            count = 0;
        }
        displayLetter('A',(int)x,(int)y); 
    }
    
    clearDisplay();
    count = 0;
    key = 6;
    
    while(mode == 1) {
        temp = checkInput(1000);
        if ((temp == 1 || temp == 2) && (temp == key)) {
            xspeed = xspeed + 1;
            if (xspeed >= 10) {
                xspeed = 10;
            }
        }
        else if ((temp == 3 || temp == 4) && (temp == key)) {
            yspeed = yspeed + 1;
            if (yspeed >= 10) {
                yspeed = 10;
            }
        }
        else if ((temp == 1 && key == 2) || (temp == 2 && key == 1)) {
            xspeed = xspeed - 1;
            if (xspeed < 0) {
                xspeed = 1;
            }
            else if (xspeed == 0) {
                key = 6;
            }
        }
        else if ((temp == 3 && key == 4) || (temp == 4 && key == 3)) {
            yspeed = yspeed - 1;
            if (yspeed < 0) {
                yspeed = 1;
            }
            else if (yspeed == 0) {
                key = 6;
            }
        }
        else if (temp != 0) {
            prev = key;
            key = temp;
        }
        
        if (key == 1 || prev == 1) {
            x = x - (xspeed * .001);
            if(x<0) {
                x=7;
            }
        }
        if (key == 2 || prev == 2) {
            x = x + (xspeed * .001);
            if(x>7) {
                x=0;
            }
        }
        if (key == 3 || prev == 3) {
            y = y - (yspeed * .001);
            if(y<0) {
                y=7;
            }
        }
        if (key == 4 || prev == 4) {
            y = y + (yspeed * .001);
            if(y>7) {
                y=0;
            }
        }
        if (key == 5) {
            mode = mode + 1;
        }
        
        clearDisplay();
        count++;
        if(count == 1000) {
            clearDisplay();
            count = 0;
        }
        displayLetter('R',(int)x,(int)y);
    }

    clearDisplay();
    refresh();
    sleep(1);
    closeDisplay();
}
