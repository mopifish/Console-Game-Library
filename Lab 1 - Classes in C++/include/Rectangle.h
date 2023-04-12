// Rectangle Header Definition
// Created by Drake on 4/6/2023.
// Implementation in Rectangle.cpp
// Simple Rectangle Class that draws a rectangle onto console

#include <utility> // Include for Pair type
#include <algorithm> // Include for clamp, max methods
#include <iostream>
#include <string>

#ifndef LAB_1___CLASSES_IN_C___RECTANGLE_H
#define LAB_1___CLASSES_IN_C___RECTANGLE_H


class Rectangle {
public:
    // -- Class Constants --
    static const int MIN_WIDTH;
    static const int MIN_HEIGHT;
    static const int MAX_WIDTH;
    static const int MAX_HEIGHT;
    static const int MIN_X_POSITION;
    static const int MIN_Y_POSITION;


    // -- Default Constructor --
    Rectangle(std::pair<int, int> = std::make_pair(1,1), std::pair<int, int> = std::make_pair(0,0), char = ' ');


    // -- Member Functions --


    // -- Set Functions --
    void set_character(char);
    void set_dimensions(std::pair<int, int>);
    void set_width(int);
    void set_height(int);
    void set_position(std::pair<int, int>);
    void set_x_position(int);
    void set_y_position(int);


    // -- Get Functions --
    char get_character() const;
    std::pair<int, int> get_dimensions() const;
    int get_width() const;
    int get_height() const;
    std::pair<int, int> get_position() const;
    int get_x_position() const;
    int get_y_position() const;

    // -- Print Functions --
    std::string to_string() const;


private:
    char character;
    std::pair<int, int> dimensions;
    std::pair<int, int> position;

};

// Print Operator Override
std::ostream& operator<<(std::ostream&, const Rectangle&);

#endif //LAB_1___CLASSES_IN_C___RECTANGLE_H
