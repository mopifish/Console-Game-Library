#include <utility>

#include "CGL/CGL.h"


struct Paddle : public GameObject {

    struct PaddleInputComponent : InputComponent{
        PaddleInputComponent(char up_key, char down_key) {
            this->up_key = up_key;
            this->down_key = down_key;
        }

        void update(PhysicsComponent* physics_component) override {
            char ch = getch();

            Shape* physics_object = physics_component->get_physics_object();
            if (ch == up_key){
                physics_object->set_y_position(physics_object->get_y_position()-1);
            } else if (ch == down_key){
                physics_object->set_y_position(physics_object->get_y_position()+1);
            }
        }

        char up_key;
        char down_key;
    };

    Paddle(std::pair<int, int> position, std::pair<char, char> keys) : GameObject(
            new RenderComponent( new Rectangle(std::make_pair(2, 10), position) ),
            new PhysicsComponent( new Rectangle(std::make_pair(2, 10), position) ),
            new PaddleInputComponent(keys.first, keys.second)
    ) {};

    void update() override{};
};

int main(){
    // Initialize Game Window
    CGL game(100, 50);

    Paddle* paddle = new Paddle(std::make_pair(0, 0), std::make_pair('w', 's'));
    game.add_game_object(paddle);
    game.add_game_object(paddle2);

    game.loop();

    return 0;
}