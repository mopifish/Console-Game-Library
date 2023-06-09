//
// Created by Drake Pickett on 4/18/2023.
//

#include "CGL/Renderer.h"
#include <utility>

Renderer::Renderer(int screen_width, int screen_height) {
    this->console = curses::console_interface(screen_width, screen_height);
}

void Renderer::render() {
    // Initialize empty screen
    std::vector<std::vector<short>> raster_screen(
            console.get_terminal_height(),
            std::vector<short>(console.get_terminal_width(), this->CLEAR_COLOR)
    );

    for (Shape* render_object : this->render_cache) {
        this->blit(render_object, &raster_screen);
    }

    for (int y = 0; y < raster_screen.size(); y++){
        for (int x = 0; x < raster_screen[y].size(); x++){
            // Get color of current grid space
            int n = raster_screen[y][x];

            //  If color pair does not exist, initialize it
            if (init_pair(n+1, n, n) != OK){
                init_pair(n+1, n, n);
            }

            // Str is doubled so shapes appear properly on console
            std::string str(2, n != 0 ? '#' : ' ');
            this->console.print(str, COLOR_PAIR(n+1), x*2, y);
        }
    }

    // Clears render cache once it's been rendered
    this->render_cache = std::vector<Shape*>();
    // Updates PD curses console
    this->console.update();

}

void Renderer::blit(Shape* render_object, std::vector<std::vector<short>>* raster_screen) {
    std::vector<std::vector<short>> raster_shape = render_object->get_raster_shape();
    const int shape_x_pos = render_object->get_x_position();
    const int shape_y_pos = render_object->get_y_position();
    const int shape_width = raster_shape[0].size();
    const int shape_height = raster_shape.size();

    // Limits drawing to raster screen bounds
    const int y_start = std::max(shape_y_pos, 0);
    const int y_end = std::min(shape_y_pos + shape_height, static_cast<int>((*raster_screen).size()));
    const int x_start = std::max(shape_x_pos, 0);
    const int x_end = std::min(shape_x_pos + shape_width, static_cast<int>((*raster_screen).size()));

    for (int y = y_start; y < y_end; y++) {
        for (int x = x_start; x < x_end; x++) {
            short cell_color = raster_shape[y-shape_y_pos][x-shape_x_pos];
            if (cell_color == CLEAR_COLOR) { continue; }

            (*raster_screen)[y][x] = cell_color;
        }
    }
}

void Renderer::add_render_object(Shape* render_object) {
    this->render_cache.push_back(render_object);
}
