//
// Created by Drake on 4/12/2023.
//

#include "Shape.h"

#include <utility>

const int Shape::MIN_X_POSITION = 0;
const int Shape::MIN_Y_POSITION = 0;

// -- Constructor Function --
Shape::Shape(std::pair<int, int> position, char character, std::vector<short> colors) {
    this->set_position(position);
    this->set_character(character);
    this->set_line_color(colors[0]);
    this->set_fill_color(colors[1]);
    this->set_character_color(colors[2]);
}

// -- Member Functions --

// -- Public Set Functions --
void Shape::set_character(char value) { this->character = value; }
void Shape::set_position(std::pair<int, int> new_position) {
    this->position = std::make_pair(
            std::max(new_position.first, MIN_X_POSITION),
            std::max(new_position.second, MIN_Y_POSITION)
    );
}
void Shape::set_x_position(int new_x_position) { this->position.first = std::max(new_x_position, MIN_X_POSITION); }
void Shape::set_y_position(int new_y_position) { this->position.second = std::max(new_y_position, MIN_Y_POSITION); }
void Shape::set_line_color(short new_line_color) { this->line_color = new_line_color; }
void Shape::set_fill_color(short new_fill_color) { this->fill_color = new_fill_color; }
void Shape::set_character_color(short new_character_color) { this->character_color = new_character_color; }

// -- Protected Set Functions --
void Shape::set_raster_shape(std::vector<std::vector<short>> new_raster_shape) { this->raster_shape = std::move(new_raster_shape); }


// -- Get Functions --
char Shape::get_character() const { return this->character; }
std::vector<std::vector<short>> Shape::get_raster_shape() const { return this->raster_shape; }
std::pair<int, int> Shape::get_position() const { return this->position; }
int Shape::get_x_position() const { return this->position.first; }
int Shape::get_y_position() const { return this->position.second; }
short Shape::get_line_color() const { return this->line_color; }
short Shape::get_fill_color() const { return this->fill_color; }
short Shape::get_character_color() const { return this->character_color; }

// -- Print Functions --
std::string Shape::to_string() const {
    std::string output;

    for (std::vector<short> vec : this->get_raster_shape()) {
        for (short c : vec) {

            char ch = '0' + c;
            output += ch;
        }

        output += "\n";
    }

    return output;
}


// -- Print Operator Override --
std::ostream& operator<<(std::ostream& os, const Shape& obj) {
    return os << obj.to_string() << std::endl;
}