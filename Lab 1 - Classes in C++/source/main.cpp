#include <iostream>
#include "Rectangle.h"
#include "console_interface.h"
// Exercise 9.11

int main(){
    // initialize PDCurses
    curses::console_interface ci();
    start_color();

    std::pair<int, int> dimensions = std::make_pair(17, 3);
    std::pair<int, int> position = std::make_pair(10, 10);

    Rectangle new_rect(dimensions, position);

    // define color pairs
    init_pair(1, COLOR_RED, COLOR_BLACK);
    // set text color
    attron(COLOR_PAIR(1)); // enable red text on black background
    std::cout << new_rect;
    attroff(COLOR_PAIR(1));

    // refresh the screen to display changes
    refresh();

    // wait for user input
    getch();

    endwin();
    return 0;
}