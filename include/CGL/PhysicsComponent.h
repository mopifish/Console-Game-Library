//
// Created by Drake on 6/9/2023.
//

#ifndef SEAGULL_PHYSICSCOMPONENT_H
#define SEAGULL_PHYSICSCOMPONENT_H

#include "PKArt/Shape.h"

class PhysicsComponent {
public:
    PhysicsComponent(Shape* physics_object);
    virtual void update();

    Shape* get_physics_object();

protected:
    Shape* physics_object;
};



#endif //SEAGULL_PHYSICSCOMPONENT_H
