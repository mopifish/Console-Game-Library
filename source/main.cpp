#include "PKArt/Rectangle.h"
#include "PKArt/Circle.h"
#include "CGL/CGL.h"

int main(){
    // Initialize Game Window
    CGL game(600, 300);

    // Initialize rectangle
    std::pair<int, int> dimensions = std::make_pair(10, 4);
    std::pair<int, int> position = std::make_pair(50, 20);
    std::vector<short> colors = {COLOR_WHITE, COLOR_RED, COLOR_WHITE};
    Rectangle rect_1(dimensions, position, colors);
    // Initialize rectangle
    dimensions = std::make_pair(12, 6);
    position = std::make_pair(49, 19);
    Rectangle rect_2(dimensions, position);
    // Initialize circle
    position = std::make_pair(0, 0);
    colors = {COLOR_CYAN, COLOR_BLUE, COLOR_WHITE};
    Circle circ(10, position, colors, ' ');
    // Initialize Circle
    position = std::make_pair(5, 5);
    colors = {COLOR_RED, COLOR_RED, COLOR_RED};
    Circle circ2(5, position, colors);


    game.add_game_object(&rect_2);
    game.add_game_object(&circ);
    game.add_game_object(&circ2);
    game.add_game_object(&rect_1);

    game.render();
    // wait for user input
    getch();


    return 0;
}