//
// Created by Drake on 4/6/2023.
//

#include "Rectangle.h"

// -- Class Constants --
const int Rectangle::MIN_WIDTH = 1;
const int Rectangle::MIN_HEIGHT = 1;
const int Rectangle::MAX_WIDTH = 20;
const int Rectangle::MAX_HEIGHT = 20;

// -- Default Constructor --
Rectangle::Rectangle(std::pair<int, int> dimensions, std::pair<int, int> position, char character) {
    this->set_dimensions(dimensions);
    this->set_position(position);
    this->set_character(character);
}

// -- Set Functions
void Rectangle::set_dimensions(std::pair<int, int> new_dimensions) {
     this->dimensions = std::make_pair(
             std::clamp(new_dimensions.first, MIN_WIDTH, MAX_WIDTH),
             std::clamp(new_dimensions.second, MIN_HEIGHT, MAX_HEIGHT)
             );
}
void Rectangle::set_width(int new_width) {
    this->dimensions.first = std::clamp(new_width, MIN_WIDTH, MAX_WIDTH);
}
void Rectangle::set_height(int new_height) {
    this->dimensions.second = std::clamp(new_height, MIN_HEIGHT, MAX_HEIGHT);
}

// -- Get Functions --
std::pair<int, int> Rectangle::get_dimensions() const {
    return this->dimensions;
}
int Rectangle::get_width() const {
    return this->dimensions.first;
}
int Rectangle::get_height() const {
    return this->dimensions.second;
}

// -- Print Functions --
std::string Rectangle::to_string() const{
    std::string rectangle_string;

    for (int i = 0; i < this->get_height(); i++) {
        rectangle_string += std::string(this->get_width(), this->get_character()) + "\n";
    }

    return this->pad_string(rectangle_string);
}









