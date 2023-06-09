//
// Created by picke on 6/5/2023.
//

#include "CGL/RenderComponent.h"


RenderComponent::RenderComponent(Shape* render_object) {
    this->render_object = render_object;
}

void RenderComponent::update(Renderer* renderer, PhysicsComponent* physics_component) {
    renderer->add_render_object(this->get_render_object());
    this->get_render_object()->set_position(physics_component->get_physics_object()->get_position());
}


Shape *RenderComponent::get_render_object() {
    return this->render_object;
}




