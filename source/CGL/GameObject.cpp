//
// Created by picke on 4/27/2023.
//

#include "CGL/GameObject.h"

#include <utility>


GameObject::GameObject(RenderComponent* render_component, PhysicsComponent* physics_component, InputComponent* input_component) {
    this->render_component = render_component;
    this->physics_component = physics_component;
    this->input_component = input_component;
}

void GameObject::_update(Renderer* renderer) {
    render_component->update(renderer, this->physics_component);
    input_component->update(this->physics_component);
    physics_component->update();
}
