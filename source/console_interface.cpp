//
// Created by Drake Pickett on 4/10/2023.
//

#include <sstream>
#include "console_interface.h"

namespace curses {
    console_interface::console_interface(bool is_color) {
        initscr();
        if (is_color){ start_color(); }
    };

    console_interface::~console_interface() {
        endwin();
    }

    void console_interface::print(std::string output, chtype attribute, int x_position, int y_position) {
        attron(attribute);

        // necessary to print multi-line strings.
        std::istringstream string_stream(output);
        std::string line;
        int num_lines = 0;
        while(std::getline(string_stream, line)){
            mvprintw(y_position + num_lines, x_position, line.c_str());
            num_lines++;

        }

        attroff(attribute);
    }

    void console_interface::update() {
        refresh();
    }



} // curses