#include <unistd.h>
#include "ncurses.h"

#define BLACK 4
#define WHITE 1
#define BLUE 5
#define GREEN 3
#define RED 2

int color;

void openDisplay(void);
void closeDisplay(void);
int wrap(int z);
void displayLetter(char letter, int xOffset, int yOffset);
void clearDisplay(void);
void openInput(void);
void closeInput(void);
int checkInput(int delay);
    
