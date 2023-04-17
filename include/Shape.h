//
// Created by Drake on 4/12/2023.
//
#include <utility> // Include for Pair type
#include <algorithm> // Include for clamp, max methods
#include <iostream>
#include <vector>
#include <string>

#ifndef LAB_1___CLASSES_IN_C___SHAPE_H
#define LAB_1___CLASSES_IN_C___SHAPE_H


class Shape {
public:
    static const int MIN_X_POSITION;
    static const int MIN_Y_POSITION;

    // -- Constructor Function --
    Shape(std::pair<int, int>, char);

    // -- Member Functions --


    // -- Set Functions --
    void set_character(char);
    void set_position(std::pair<int, int>);
    void set_x_position(int);
    void set_y_position(int);

    // -- Get Functions --
    char get_character() const;
    std::vector<std::vector<char>> get_raster_shape() const;
    std::pair<int, int> get_position() const;
    int get_x_position() const;
    int get_y_position() const;

    // -- Print Functions --
    std::string to_string() const;

private:
    char character;
    std::vector<std::vector<char>> raster_shape;
    std::pair<int, int> position;

protected:
    // -- Set Functions --
    void set_raster_shape(std::vector<std::vector<char>>);

    // -- Helper Functions --
    virtual std::vector<std::vector<char>> make_raster_shape() = 0; // pure virtual

};

// Print Operator Override
std::ostream& operator<<(std::ostream&, const Shape&);

#endif //LAB_1___CLASSES_IN_C___SHAPE_H
