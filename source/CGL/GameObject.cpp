//
// Created by picke on 4/27/2023.
//

#include <utility>

#include "CGL/GameObject.h"

GameObject::GameObject(std::vector<Component*> components) {
    this->components = std::move(components);
}

std::vector<Component *> GameObject::get_components() {
    return this->components;
}
