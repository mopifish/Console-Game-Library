//
// Created by Drake on 4/6/2023.
//

#include "PKArt/Rectangle.h"

// -- Class Constants --
const int Rectangle::MIN_WIDTH = 1;
const int Rectangle::MIN_HEIGHT = 1;
const int Rectangle::MAX_WIDTH = 20;
const int Rectangle::MAX_HEIGHT = 20;

// -- Default Constructor --
Rectangle::Rectangle(std::pair<int, int> dimensions, std::pair<int, int> position, std::vector<short> colors, char character) : Shape(position, character, colors) {
    this->set_dimensions(dimensions);
}

// -- Set Functions
void Rectangle::set_dimensions(std::pair<int, int> new_dimensions) {
     this->dimensions = std::make_pair(
             std::clamp(new_dimensions.first, MIN_WIDTH, MAX_WIDTH),
             std::clamp(new_dimensions.second, MIN_HEIGHT, MAX_HEIGHT)
             );

    this->set_raster_shape(this->make_raster_shape());
}
void Rectangle::set_width(int new_width) {
    this->set_dimensions (
            std::make_pair (
                    std::clamp(new_width, MIN_WIDTH, MAX_WIDTH),
                    this->get_height()
            )
    );
}
void Rectangle::set_height(int new_height) {
    this->set_dimensions (
            std::make_pair (
                    this->get_width(),
                    this->dimensions.second = std::clamp(new_height, MIN_HEIGHT, MAX_HEIGHT)
            )
    );
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

std::vector<std::vector<short>> Rectangle::make_raster_shape() {
    const short line_color = this->get_line_color();
    const short fill_color = this->get_fill_color();

    const int shape_height = this->get_height();
    const int shape_width = this->get_width();

    // Generates 2d Vector of given height and given width, filled with given color
    std::vector<std::vector<short>> raster_shape (
            shape_height,
            std::vector<short>(shape_width, fill_color)
    );

    // Returns shape if adding borders isn't necessary
    if (line_color == fill_color){ return raster_shape; }

    // Top and bottom border
    for (int i = 0; i < shape_width; i++){
        raster_shape[0][i] = line_color;
        raster_shape[shape_height-1][i] = line_color;
    }

    // Left and Right Border
    for (int i = 0; i < shape_height;  i++){
        raster_shape[i][0] = line_color;
        raster_shape[i][shape_width - 1] = line_color;
    }

    return raster_shape;
}








