//
// Created by picke on 6/5/2023.
//

#ifndef SEAGULL_SHAPECOMPONENT_H
#define SEAGULL_SHAPECOMPONENT_H

#include "Component.h"
#include "PKArt/Shape.h"

class ShapeComponent : public Component {
public:
    ShapeComponent(Shape* render_object);

    bool is_renderable = true;

    Shape* get_render_object();
private:
    Shape* render_object;
};


#endif //SEAGULL_SHAPECOMPONENT_H
