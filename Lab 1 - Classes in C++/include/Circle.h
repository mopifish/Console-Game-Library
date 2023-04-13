//
// Created by Drake on 4/12/2023.
//

#include "Shape.h"

#ifndef LAB_1___CLASSES_IN_C___CIRCLE_H
#define LAB_1___CLASSES_IN_C___CIRCLE_H


class Circle : public Shape {
public:
    Circle(int = 1, std::pair<int, int> = std::make_pair(0, 0), char = '#');

    // -- Set Functions --
    void set_radius(int);
    void set_diameter(int);


    // -- Get Functions --
    int get_radius() const;
    int get_diameter() const;

    std::string to_string() const override;

private:

    int radius;




};


#endif //LAB_1___CLASSES_IN_C___CIRCLE_H
