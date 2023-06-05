//
// Created by picke on 6/5/2023.
//

#include "CGL/GraphicsComponent.h"


GraphicsComponent::GraphicsComponent(Shape* render_object) {
    this->render_object = render_object;
}
void GraphicsComponent::update() {
    this->render_object->set_position(this->parent.get_position());
}


