//
// Created by Drake on 4/12/2023.
//

#include "Circle.h"

Circle::Circle(int radius, std::pair<int, int> position, char character) {
    this->set_radius(radius);
    this->set_position(position);
    this->set_character(character);
}

// -- Set Functions --
void Circle::set_radius(int radius) {
    this->radius = radius;
}
void Circle::set_diameter(int diameter) {
    this->radius  = diameter/2;
}

// -- Get Functions --
int Circle::get_radius() const {
    return this->radius;
}
int Circle::get_diameter() const {
    return this->radius*2;
}

// -- Print Functions --
std::string Circle::to_string() const {
    std::string circle_string;

    // Top Half
    for (int i = this->get_diameter()%2; i <= this->get_diameter(); i+=2){
        circle_string += std::string((this->get_diameter()-i)/2, ' ');
        circle_string += std::string(i, this->get_character()) + "\n";
    }

    // Bottom Half
    for (int i = this->get_diameter() - 2; i >= 0; i -= 2){
        circle_string += std::string((this->get_diameter()-i)/2, ' ');
        circle_string += std::string(i, this->get_character()) + "\n";
    }


    return circle_string;
}
