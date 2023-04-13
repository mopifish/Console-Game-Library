//
// Created by Drake on 4/12/2023.
//

#include "Shape.h"

const int Shape::MIN_X_POSITION = 0;
const int Shape::MIN_Y_POSITION = 0;

// -- Member Functions
std::string Shape::pad_string(std::string str) {
    std::string new_str;

    for (char ch : str){
        new_str += ' ';
        new_str += ch;
    }

    return new_str;
}

// -- Set Functions --
void Shape::set_character(char value) {
    this->character = value;
}
void Shape::set_position(std::pair<int, int> new_position) {
    this->position = std::make_pair(
            std::max(new_position.first, MIN_X_POSITION),
            std::max(new_position.second, MIN_Y_POSITION)
    );
}
void Shape::set_x_position(int new_x_position) {
    this->position.first = std::max(new_x_position, MIN_X_POSITION);
}
void Shape::set_y_position(int new_y_position) {
    this->position.second = std::max(new_y_position, MIN_Y_POSITION);
}

// -- Get Functions --
char Shape::get_character() const {
    return this->character;
}
std::pair<int, int> Shape::get_position() const {
    return this->position;
}
int Shape::get_x_position() const {
    return this->position.first;
}
int Shape::get_y_position() const {
    return this->position.second;
}


//// -- Print Functions --


// -- Print Operator Override --
std::ostream& operator<<(std::ostream& os, const Shape& obj) {
    std::string shape_string = obj.to_string();

    os << shape_string << std::endl;
    return os;
}