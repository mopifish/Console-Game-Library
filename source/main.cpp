#include "CGL/CGL.h"

int main(){
    // Initialize Game Window
    CGL game(600, 300);

//    // Initialize rectangle
    std::pair<int, int> dimensions = std::make_pair(10, 4);
    std::pair<int, int> position = std::make_pair(50, 20);
    std::vector<short> colors = {COLOR_WHITE, COLOR_RED, COLOR_WHITE};

    class Paddle : public GameObject {
        Paddle(std::vector<Component *> components = std::vector<Component*>{
            //&ShapeComponent( &Rectangle(dimensions, position, colors) )
        }) : GameObject(components){};
    };

    Paddle paddle();
    game.add_game_object(&paddle);

    game.render();
    // wait for user input
    getch();


    return 0;
}