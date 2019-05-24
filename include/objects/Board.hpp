#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
using namespace std;

#include "objects/Window.hpp"
#include "objects/GameObject.hpp"
#include "objects/Viewport.hpp"

class Board {
public:
        // Data
        GameObject* board[10][10];
        Viewport *viewport;
        unsigned int tile_size = 64;

        // Methods
        Board(Viewport *viewport);
        ~Board();
        void draw(Window *window);
        SDL_Rect get_object_position(GameObject *object);
};

#endif
