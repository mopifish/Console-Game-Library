//
// Created by picke on 4/27/2023.
//

#ifndef SEAGULL_COMPONENT_H
#define SEAGULL_COMPONENT_H

#include "CGL/game_object.h"

class Component {
public:
    virtual void update() = 0;

    bool is_renderable = false;
};


#endif //SEAGULL_COMPONENT_H
