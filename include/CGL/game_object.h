//
// Created by picke on 4/27/2023.
//
#include <vector>
#include "Component.h"

#ifndef SEAGULL_GAME_OBJECT_H
#define SEAGULL_GAME_OBJECT_H


class game_object {
public:
    game_object(std::vector<Component*>);

    void update();

private:
    std::vector<Component*> components;

};


#endif //SEAGULL_GAME_OBJECT_H
