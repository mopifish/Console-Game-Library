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

    std::vector<std::vector<char>> raster(d+1, std::vector<char>(d+1, 'x'));

    for (int y = r;  y > 0; y--){
        // Circle equation: x^2 + y^2 = r^2
        // We have Y, and we have R, now solve for X.
        // x = sqrt(r^2 - y^2)
        // This gives us two possible answers for x, pos and neg
        int x = round(sqrt(pow(r, 2) - pow(y, 2)));
        std::cout << abs(y-r) << ", " << x+r << " : " << x+r - (x+r)%r << std::endl;
        raster[abs(y-r)][x+r] = this->get_character();
        raster[abs(y-r)][] = this->get_character();
    }

    return raster;
}



