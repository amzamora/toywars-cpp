#ifndef VIEWPORT_HPP
#define VIEWPORT_HPP

#include "SDL2/SDL.h"

#include "objects/Input.hpp"

class Viewport {
public:
        // Data
        int x;
        int y;
        unsigned int width;
        unsigned int height;

        float scale;

        // Methods
        Viewport(int x, int y, unsigned int width, unsigned int height);
        ~Viewport();
        bool its_on_screen(SDL_Rect position);

        void update(Input *input);
};

#endif
