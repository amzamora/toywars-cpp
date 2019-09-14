#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "objects/Window.hpp"

class GameObject {
public:
        // Data
        unsigned int row;
        unsigned int column;

        // Methods
        virtual ~GameObject() {};
        virtual void draw(Window *window, SDL_Rect dst) = 0;
        virtual void update() = 0;
};


#endif
