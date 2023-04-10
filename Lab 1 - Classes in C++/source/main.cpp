#include <iostream>
#include "Rectangle.h"
#include "PDCurses/curses.h"
// Exercise 9.11

int main(){
    std::pair<int, int> dimensions = std::make_pair(17, 3);
    std::pair<int, int> position = std::make_pair(10, 10);

    Rectangle new_rect(dimensions, position);

    std::cout << new_rect;

    return 0;
}