//
// Created by Drake Pickett on 4/18/2023.
// Renderer, Console Game Library, or the Seeg Library is a custom library meant for use in making
// games for the windows terminal


#ifndef PKART_CGL_H
#define PKART_CGL_H

#include <vector>

#include "console_interface.h"
#include "PKArt/PKArt.h"

class Renderer {
public:
    const short CLEAR_COLOR = COLOR_BLACK;

    Renderer(int = 600, int = 300);

    void render();

    void add_render_object(Shape*);

    void blit(Shape*, std::vector<std::vector<short>>*);



private:
    curses::console_interface console;
    std::vector<Shape*> render_cache;
};


#endif //PKART_CGL_H