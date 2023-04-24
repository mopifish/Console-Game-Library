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
    Shape(std::pair<int, int>, char, std::vector<short>);

    // -- Member Functions --


    // -- Set Functions --
    void set_character(char);
    void set_position(std::pair<int, int>);
    void set_x_position(int);
    void set_y_position(int);
    void set_line_color(short);
    void set_fill_color(short);
    void set_character_color(short);

    // -- Get Functions --
    char get_character() const;
    std::vector<std::vector<short>> get_raster_shape() const;
    std::pair<int, int> get_position() const;
    int get_x_position() const;
    int get_y_position() const;
    short get_line_color() const;
    short get_fill_color() const;
    short get_character_color() const;

    // -- Print Functions --
    std::string to_string() const;

private:
    char character;
    std::vector<std::vector<short>> raster_shape;
    std::pair<int, int> position;
    short line_color;
    short fill_color;
    short character_color;

protected:
    // -- Set Functions --
    void set_raster_shape(std::vector<std::vector<short>>);

    // -- Helper Functions --
    virtual std::vector<std::vector<short>> make_raster_shape() = 0; // pure virtual

};

// Print Operator Override
std::ostream& operator<<(std::ostream&, const Shape&);

#endif //LAB_1___CLASSES_IN_C___SHAPE_H
