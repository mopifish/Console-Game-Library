//
// Created by Drake on 4/12/2023.
//

#include <cmath>
#include "Circle.h"

Circle::Circle(int radius, std::pair<int, int> position, std::vector<short> colors, char character) : Shape(position, character, colors) {
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

std::vector<std::vector<short>> Circle::make_raster_shape() {
    const int d = this->get_diameter();
    const int r = this->get_radius();
    const short lc = this->get_line_color();
    const short fc = this->get_fill_color();

    std::vector<std::vector<short>> raster(d, std::vector<short>(d, 0));

    for (int y = r; y > 0 ; y--) {
        // Circle equation: x^2 + y^2 = r^2
        // We have Y, and we have R, now solve for X.
        // x = sqrt(r^2 - y^2)
        // We can then add this point and mirror it 8 ways

        // Use the above equation to calculate the X position. Then round it to the nearest pixel
        int x = round(sqrt(pow(r, 2) - pow(y, 2)));

        // Draw Circle
        // Note: -1 must be added anytime X or Y is negative. This is to account for
        // Vectors going from 0 to 19. Math is done in 0 to 20.
        raster[abs(y-r)][abs(x-r)] = lc; // Upper Mid Left
        raster[abs(-y - r)-1][abs(x - r)] = lc; // Lower Mid Left
        raster[abs(y - r)][abs(-x-r)-1] = lc; // Upper Mid Right
        raster[abs(-y - r)-1][abs(-x - r)-1] = lc; // Lower Mid Right
        raster[abs(x-r)][abs(y - r )] = lc; // Top Left
        raster[abs(-x-r)-1][abs(y - r)] = lc; // Bottom Left
        raster[abs(-x -r)-1][abs(-y - r)-1] = lc; // Bottom Right
        raster[abs(x -r)][abs(-y - r) -1] = lc; // Top Right
    }

    // Fill circle
    for (int y = 0; y < d; y++) {
        // Skip first and last lines, which are filled by default
        if (y == 0 || y == d-1) {continue;}
        for (int x = 0; x < d; x++) {
            // If empty space, re-loop
            if (raster[y][x] == 0) { continue; }

            // If line non-empty space found, loop until empty space is found (inside of circle)
            int sp = 1;
            while(raster[y][x+sp] != 0 ){ sp++; };
            // Now in empty space, loop until other side is hit
            for (int i = x+sp; i < d; i++) {
                if (raster[y][i] == 0) { raster[y][i] = fc; }
                else { break; }
            }

            // With line filled, break loop and head to next line
            break;
        }
    }

    return raster;
}



