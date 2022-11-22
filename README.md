# Scrolling-Display
A program that displays scrolling letters that can change speed, direction, color, and more.

## Main Program Function:
Displays the letters of my initials (AR) and allows the user to move the currently displayed letter, or scroll, with increasing/decreasing speed using the arrow keys.

## How the Program Works:
* When the program is started, the first initial is displayed.
* When the "change letter" control is activated (by pressing the "return" key), the letter changes to the next initial.
* When an arrow key is pressed, the current letter on the display begins scrolling in that direction, starting at about one pixel per second. Each additional press of the same arrow key will speed it up. Pressing the arrow key of the opposite direction will slow and eventually reverse the scrolling.
  * Vertical, horizontal, and diagonal scrolling are all supported.

## How to Run the Program:
1) Type the following commands in the command line:
      > $ make  
	      $ ./scroll  
    * The first letter will then pop up, and pressing the arrow keys will cause the letter to scroll in the appropriate direction and speed.
2) To switch to the next letter, press Enter.
3) To exit the program, press Enter again.

## Extra Command Line Arguments Supported:
> $ ./scroll **-h**
* Explains how to run the program and then exits.
> $ ./scroll **-c COLOR**
* Sets the scrolling display color to the color given. COLOR may be one of white, red, green, or blue.
> $ ./scroll **-nskip**
* Skips directly to the second letter and then displays the number of command-line arguments the user passed.
