#include "Rectangle.h"
#include "Circle.h"
#include "console_interface.h"
// Exercise 9.11

int main(){

    // initialize PDCurses
    curses::console_interface cons(/* is_color = */ true);

    // Initialize rectangle
    std::pair<int, int> dimensions = std::make_pair(17, 3);
    std::pair<int, int> position = std::make_pair(10, 10);
    Rectangle rect_1(dimensions, position);

    // Initialize rectangle
    dimensions = std::make_pair(5, 5);
    position = std::make_pair(13, 4);
    Rectangle rect_2(dimensions, position);

    // Initialize circle
    position = std::make_pair(10, 10);
    Circle circ(6, position);


    // define color pairs
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
//
//    cons.print(rect_1.to_string(), COLOR_PAIR(1), rect_1.get_x_position(), rect_1.get_y_position());
//    cons.print(rect_2.to_string(), COLOR_PAIR(2), rect_2.get_x_position(), rect_2.get_y_position());
    cons.print(circ.to_string(), COLOR_PAIR(2), circ.get_x_position(), circ.get_y_position());
    cons.update();

    // wait for user input
    getch();

    return 0;
}