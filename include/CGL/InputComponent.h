//
// Created by Drake on 6/9/2023.
//

#ifndef SEAGULL_INPUTCOMPONENT_H
#define SEAGULL_INPUTCOMPONENT_H

#include "PhysicsComponent.h"
#include "Renderer.h"
#include "PKArt/Shape.h"

class InputComponent {
public:
    virtual void update(PhysicsComponent* physics_component) = 0;
};



#endif //SEAGULL_INPUTCOMPONENT_H
