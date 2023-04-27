//
// Created by Drake Pickett on 4/18/2023.
// CGL, Console Game Library, or the Seeg Library is a custom library meant for use in making
// games for the windows terminal

#include "console_interface.h"
#include <vector>
#include "PKArt/Shape.h"

#ifndef PKART_CGENGINE_H
#define PKART_CGENGINE_H


class CGL {
public:
    const short CLEAR_COLOR = COLOR_BLACK;

    CGL(int = 600, int = 300, std::vector<Shape*> = std::vector<Shape*>());

    void render();

    void add_game_object(Shape*);

    void blit(Shape*, std::vector<std::vector<short>>*);

private:
    curses::console_interface console;
    std::vector<Shape*> game_objects;
};


#endif //PKART_CGENGINE_H