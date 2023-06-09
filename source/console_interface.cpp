//
// Created by Drake Pickett on 4/10/2023.
//

#include <sstream>
#include "console_interface.h"

namespace curses {
    console_interface::console_interface(int terminal_width, int terminal_height, bool is_color) {
        initscr();
        cbreak();
        noecho();
        nodelay(stdscr, true); // Set getch to non-blocking mode
        if (is_color){ start_color(); }
        this->set_terminal_size(std::make_pair(terminal_width, terminal_height));
    };

    console_interface::~console_interface() {
        endwin();
    }

    // -- Member Functions --
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

    // -- Set Functions --
    void console_interface::set_terminal_size(std::pair<int, int> new_terminal_size) {
        resize_term(new_terminal_size.second, new_terminal_size.first);
        this->terminal_size = new_terminal_size;
    }
    void console_interface::set_terminal_width(int new_width) {
        this->set_terminal_size(std::make_pair(new_width, this->get_terminal_height()));
    }
    void console_interface::set_terminal_height(int new_height) {
        this->set_terminal_size(std::make_pair(this->get_terminal_width(), new_height));
    }


    // -- Get Functions --
    std::pair<int, int> console_interface::get_terminal_size() const {
        return this->terminal_size;
    }
    int console_interface::get_terminal_width() const {
        return this->get_terminal_size().first;
    }
    int console_interface::get_terminal_height() const {
        return this->get_terminal_size().second;
    }




} // curses