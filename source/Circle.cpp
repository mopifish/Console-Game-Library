//
// Created by Drake on 4/12/2023.
//

#include <cmath>
#include "Circle.h"

Circle::Circle(int radius, std::pair<int, int> position, char character) : Shape(position, character) {
    this->set_radius(radius);

}

// -- Set Functions --
void Circle::set_radius(int radius) {
    this->radius = radius;

    this->set_raster_shape(this->make_raster_shape());
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

std::vector<std::vector<char>> Circle::make_raster_shape() {
    const int d = this->get_diameter();
    const int r = this->get_radius();
    const char c = this->get_character();

    std::vector<std::vector<char>> raster(d, std::vector<char>(d, ' '));

    for (int y = r; y > 0 ; y--) {
        // Circle equation: x^2 + y^2 = r^2
        // We have Y, and we have R, now solve for X.
        // x = sqrt(r^2 - y^2)
        // This gives us two possible answers for x, pos and neg
        // We can then mirror this across the Y-axis


        // Use the above equation to calculate the X position. Then round it to the nearest pixel
        int x = round(sqrt(pow(r, 2) - pow(y, 2)));

        // Draw Circle
        // Note: -1 must be added anytime X or Y is negative. This is to account for
        // Vectors going from 0 to 19. Math is done in 0 to 20.
        raster[abs(y-r)][abs(x-r)] = c; // Upper Mid Left
        raster[abs(-y - r)-1][abs(x - r)] = c; // Lower Mid Left
        raster[abs(y - r)][abs(-x-r)-1] = c; // Upper Mid Right
        raster[abs(-y - r)-1][abs(-x - r)-1] = c; // Lower Mid Right
        raster[abs(x-r)][abs(y - r )] = c; // Top Left
        raster[abs(-x-r)-1][abs(y - r)] = c; // Bottom Left
        raster[abs(-x -r)-1][abs(-y - r)-1] = c; // Bottom Right
        raster[abs(x -r)][abs(-y - r) -1] = c; // Top Right
    }

    return raster;
}



