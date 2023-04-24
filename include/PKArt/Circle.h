//
// Created by Drake on 4/12/2023.
//

#include "Shape.h"

#ifndef LAB_1___CLASSES_IN_C___CIRCLE_H
#define LAB_1___CLASSES_IN_C___CIRCLE_H


class Circle : public Shape {
public:
    Circle(int = 1, std::pair<int, int> = std::make_pair(0, 0), std::vector<short> = {1, 1, 1}, char = '#');

    // -- Set Functions --
    void set_radius(int);
    void set_diameter(int);


    // -- Get Functions --
    int get_radius() const;
    int get_diameter() const;


private:
    int radius;

    // -- Helper Functions --
    std::vector<std::vector<short>> make_raster_shape() override;



};


#endif //LAB_1___CLASSES_IN_C___CIRCLE_H
