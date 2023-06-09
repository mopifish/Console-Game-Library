//
// Created by Drake on 6/9/2023.
//

#include "CGL/PhysicsComponent.h"

PhysicsComponent::PhysicsComponent(Shape *physics_object) {
    this->physics_object = physics_object;
}

Shape *PhysicsComponent::get_physics_object() {
    return this->physics_object;
}

void PhysicsComponent::update() {

}
