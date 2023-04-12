//
// Created by picke on 4/10/2023.
// Wrapper class for the curses library

#include "PDCurses/curses.h"
#include <string>

#ifndef LAB_1___CLASSES_IN_C___CONSOLEINTERFACE_H
#define LAB_1___CLASSES_IN_C___CONSOLEINTERFACE_H

namespace curses {

    class console_interface {

    public:
        console_interface(bool);
        ~console_interface();

        void print(std::string, chtype = 0, int = 0, int = 0);

        void update();
    };

} // curses

#endif //LAB_1___CLASSES_IN_C___CONSOLEINTERFACE_H
