//
// Created by picke on 6/5/2023.
//

#include "CGL/ShapeComponent.h"


ShapeComponent::ShapeComponent(Shape* render_object) {
    this->render_object = render_object;
}

Shape *ShapeComponent::get_render_object() {
    return this->render_object;
}



