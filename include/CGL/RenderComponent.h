//
// Created by picke on 6/5/2023.
//

#ifndef SEAGULL_RENDERCOMPONENT_H
#define SEAGULL_RENDERCOMPONENT_H

#include "PhysicsComponent.h"
#include "Renderer.h"
#include "PKArt/Shape.h"

class RenderComponent {
public:
    RenderComponent(Shape* render_object);
    virtual void update(Renderer* renderer, PhysicsComponent* physics_component);

    Shape* get_render_object();
private:
    Shape* render_object;
};


#endif //SEAGULL_RENDERCOMPONENT_H
