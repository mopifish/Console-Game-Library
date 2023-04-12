//
// Created by Drake on 4/6/2023.
//

#include "Rectangle.h"

// -- Class Constants --
const int Rectangle::MIN_WIDTH = 1;
const int Rectangle::MIN_HEIGHT = 1;
const int Rectangle::MAX_WIDTH = 20;
const int Rectangle::MAX_HEIGHT = 20;
const int Rectangle::MIN_X_POSITION = 0;
const int Rectangle::MIN_Y_POSITION = 0;


// -- Default Constructor --
Rectangle::Rectangle(std::pair<int, int> dimensions, std::pair<int, int> position, char character) {
    this->dimensions = dimensions;
    this->position = position;
    this->character = character;
}


// -- Set Functions
void Rectangle::set_character(char value) {
    this->character = value;
}
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
void Rectangle::set_position(std::pair<int, int> new_position) {
    this->position = std::make_pair(
            std::max(new_position.first, MIN_X_POSITION),
            std::max(new_position.second, MIN_Y_POSITION)
    );
}
void Rectangle::set_x_position(int new_x_position) {
    this->position.first = std::max(new_x_position, MIN_X_POSITION);
}
void Rectangle::set_y_position(int new_y_position) {
    this->position.second = std::max(new_y_position, MIN_Y_POSITION);
}


// -- Get Functions --
char Rectangle::get_character() const {
    return this->character;
}
std::pair<int, int> Rectangle::get_dimensions() const {
    return this->dimensions;
}
int Rectangle::get_width() const {
    return this->dimensions.first;
}
int Rectangle::get_height() const {
    return this->dimensions.second;
}
std::pair<int, int> Rectangle::get_position() const {
    return this->position;
}
int Rectangle::get_x_position() const {
    return this->position.first;
}
int Rectangle::get_y_position() const {
    return this->position.second;
}

std::string Rectangle::to_string() const {
    std::string rectangle_string;

    for (int i = 0; i < this->get_height(); i++) {
        rectangle_string += std::string(this->get_width(), this->character) + "\n";
    }

    return rectangle_string;
}


// -- Print Operator Override --
std::ostream& operator<<(std::ostream& os, const Rectangle& obj) {
    std::string rectangle_string = obj.to_string();

    os << rectangle_string << std::endl;
    return os;
}






