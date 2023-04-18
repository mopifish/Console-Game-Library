#include "Rectangle.h"
#include "Circle.h"
#include "console_interface.h"
// Exercise 9.11

std::string pad_string(std::string str) {
    std::string new_str;

    for (char c : str){
        new_str += ' ';
        new_str += c;
    }

    return new_str;
}

int main(){

    // initialize PDCurses
    curses::console_interface cons(/* is_color = */ true);

    // Initialize rectangle
    std::pair<int, int> dimensions = std::make_pair(17, 3);
    std::pair<int, int> position = std::make_pair(20, 20);
    Rectangle rect_1(dimensions, position);

    // Initialize rectangle
    dimensions = std::make_pair(5, 5);
    position = std::make_pair(13, 4);
    Rectangle rect_2(dimensions, position);

    // Initialize circle
    position = std::make_pair(0, 0);
    std::vector<short> colors = {COLOR_CYAN, COLOR_BLUE, COLOR_WHITE};
    Circle circ(10, position, colors, '~');

    position = std::make_pair(10, 5);
    Circle circ2(5, position);

    std::vector<std::vector<short>> raster_shape = circ.get_raster_shape();
    for (int y = 0; y < raster_shape.size(); y++){
        for (int x = 0; x < raster_shape[y].size(); x++){
            // Get color of current grid space
            int n = raster_shape[y][x];

            //  If color pair does not exist, initialize it
            if (init_pair(n+1, circ.get_character_color(), n) != OK){
                init_pair(n+1, circ.get_character_color(), n);
            }

            // Str is doubled so shapes appear properly on console
            std::string str(2, n != 0 ? circ.get_character() : ' ');
            cons.print(str, COLOR_PAIR(n+1), x*2, y);
        }
    }
    //cons.print(pad_string(circ2.to_string()), COLOR_PAIR(2), circ2.get_x_position(), circ2.get_y_position());

    cons.update();

    // wait for user input
    getch();


    return 0;
}