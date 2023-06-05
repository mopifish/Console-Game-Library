//
// Created by picke on 4/27/2023.
//

#include <utility>

#include "CGL/game_object.h"

game_object::game_object(std::vector<Component*> components) {
    this->components = std::move(components);
}

void game_object::update() {
    for (Component* c : this->components) {
        c->update();
        if (c->is_renderable){
            c->render();
        }
    }
}
