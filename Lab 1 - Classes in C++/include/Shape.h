//
// Created by Drake on 4/12/2023.
//
#include <utility> // Include for Pair type
#include <algorithm> // Include for clamp, max methods
#include <iostream>
#include <string>

#ifndef LAB_1___CLASSES_IN_C___SHAPE_H
#define LAB_1___CLASSES_IN_C___SHAPE_H


class Shape {
public:
    static const int MIN_X_POSITION;
    static const int MIN_Y_POSITION;

    // -- Set Functions --
    void set_character(char);
    void set_position(std::pair<int, int>);
    void set_x_position(int);
    void set_y_position(int);

    // -- Get Functions --
    char get_character() const;
    std::pair<int, int> get_position() const;
    int get_x_position() const;
    int get_y_position() const;

    // -- Print Functions --
    virtual std::string to_string() const;

private:
    char character;
    std::pair<int, int> position;

};

// Print Operator Override
std::ostream& operator<<(std::ostream&, const Shape&);

#endif //LAB_1___CLASSES_IN_C___SHAPE_H
