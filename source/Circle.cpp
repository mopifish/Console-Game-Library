//
// Created by Drake on 4/12/2023.
//

#include <cmath>
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
float DegreesToRadians(int degrees) {
    return degrees * (M_PI / 180);
}
std::string Circle::to_string() const {
    std::string circle_string;

    int x = this->get_radius() * cos(DegreesToRadians(30));
    int y = this->get_radius() * sin(DegreesToRadians(30));

    for (int i = 0; i < x - y; i++){
        circle_string += std::string(x-y-i, ' ');
        circle_string += std::string(i, this->get_character());
        circle_string += std::string(y*2, this->get_character());
        circle_string += std::string(i, this->get_character());
        circle_string += "\n";

    }
    for (int i = 0; i < y * 2; i++){
        circle_string += std::string(x*2, this->get_character()) + "\n";
    }
    for (int i = x-y-1; i >= 0; i--){
        circle_string += std::string(x-y-i, ' ');
        circle_string += std::string(i, this->get_character());
        circle_string += std::string(y*2, this->get_character());
        circle_string += std::string(i, this->get_character());
        circle_string += "\n";

    }

    return this->pad_string(circle_string);
}


