//
// Created by picke on 6/5/2023.
//

#ifndef SEAGULL_GRAPHICSCOMPONENT_H
#define SEAGULL_GRAPHICSCOMPONENT_H

#include "Component.h"
#include "PKArt/Shape.h"

class GraphicsComponent : public Component {
public:
    GraphicsComponent(Shape* render_object);
    void update() override;

    bool is_renderable = true;

private:
    Shape* render_object;
};


#endif //SEAGULL_GRAPHICSCOMPONENT_H
