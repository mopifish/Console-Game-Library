//
// Created by picke on 4/10/2023.
// Wrapper class for the curses library

#include "PDCurses/curses.h"
#include <string>
#include <vector>

#ifndef LAB_1___CLASSES_IN_C___CONSOLEINTERFACE_H
#define LAB_1___CLASSES_IN_C___CONSOLEINTERFACE_H

namespace curses {

    class console_interface {

    public:
        console_interface(int = 100, int = 25, bool  = true);
        ~console_interface();

        // -- Member Functions --
        void print(std::string, chtype = 0, int = 0, int = 0);
        void update();

        // -- Set Functions --
        void set_terminal_size(std::pair<int, int>);
        void set_terminal_width(int);
        void set_terminal_height(int);


        // -- Get Functions --
        std::pair<int, int> get_terminal_size() const;
        int get_terminal_width() const;
        int get_terminal_height() const;


    private:
        std::pair<int, int> terminal_size;
    };

} // curses

#endif //LAB_1___CLASSES_IN_C___CONSOLEINTERFACE_H
