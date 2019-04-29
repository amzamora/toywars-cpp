#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
using namespace std;

#include "objects/Window.hpp"
#include "objects/GameObject.hpp"

class Board {
public:
        // Data
        vector<GameObject*> objects;

        // Methods
        Board();
        ~Board();
        void draw(Window *window);
};

#endif
