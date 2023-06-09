//
// Created by Drake on 6/9/2023.
//

#ifndef SEAGULL_CGL_H
#define SEAGULL_CGL_H

#include "CGL/Renderer.h"
#include "CGL/GameObject.h"

class CGL {
public:
    CGL(int = 600, int = 300);

    void loop();

    void add_game_object(GameObject* object);
private:
    void update();

    Renderer renderer;
    std::vector<GameObject*> game_objects;
};

#endif //SEAGULL_CGL_H
