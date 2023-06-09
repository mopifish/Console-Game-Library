//
// Created by picke on 4/27/2023.
//

#ifndef SEAGULL_GAME_OBJECT_H
#define SEAGULL_GAME_OBJECT_H

#include <vector>

#include "Components.h"

class GameObject {
public:
    GameObject(RenderComponent* render_component, PhysicsComponent* physics_component, InputComponent* input_component);

    void _update(Renderer* renderer);
    virtual void update() = 0;

    RenderComponent* render_component = nullptr;
    PhysicsComponent* physics_component = nullptr;
    InputComponent* input_component = nullptr;
};


#endif //SEAGULL_GAME_OBJECT_H
