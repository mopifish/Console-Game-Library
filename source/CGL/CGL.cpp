//
// Created by Drake on 6/9/2023.
//

#include "CGL/CGL.h"

CGL::CGL(int window_width, int window_height) : renderer(window_width, window_height) {}

void CGL::loop() {
    while(true) {
        this->update();
        this->renderer.render();
    }
}

void CGL::update() {
    for (GameObject* c : game_objects) {
        c->_update(&this->renderer);
        c->update();
    }
}

void CGL::add_game_object(GameObject* object) {
    this->game_objects.push_back(object);
}

