//
// Created by picke on 4/27/2023.
//

#ifndef SEAGULL_GAME_OBJECT_H
#define SEAGULL_GAME_OBJECT_H

#include <vector>

#include "GameObject.h"
#include "Component.h"
#include "ShapeComponent.h"

class GameObject {
public:
    GameObject(std::vector<Component*>);
    virtual void update() = 0;

    std::vector<Component*> get_components();
private:
    std::vector<Component*> components;

};


#endif //SEAGULL_GAME_OBJECT_H
