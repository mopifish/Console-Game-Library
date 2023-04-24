// Rectangle Header Definition
// Created by Drake on 4/6/2023.
// Implementation in Rectangle.cpp
// Simple Rectangle Class that draws a rectangle onto console

#include "Shape.h"

#ifndef LAB_1___CLASSES_IN_C___RECTANGLE_H
#define LAB_1___CLASSES_IN_C___RECTANGLE_H


class Rectangle : public Shape {
public:
    // -- Class Constants --
    static const int MIN_WIDTH;
    static const int MIN_HEIGHT;
    static const int MAX_WIDTH;
    static const int MAX_HEIGHT;

    // -- Default Constructor --
    Rectangle(std::pair<int, int> = std::make_pair(1,1), std::pair<int, int> = std::make_pair(0,0), std::vector<short> = {2, 2, 2}, char = '#');

    // -- Member Functions --


    // -- Set Functions --
    void set_dimensions(std::pair<int, int>);
    void set_width(int);
    void set_height(int);

    // -- Get Functions --
    std::pair<int, int> get_dimensions() const;
    int get_width() const;
    int get_height() const;


private:
    std::pair<int, int> dimensions;

protected:
    // -- Helper function --
    std::vector<std::vector<short>> make_raster_shape() override;

};

#endif //LAB_1___CLASSES_IN_C___RECTANGLE_H
