#ifndef VIEWPORT_HPP
#define VIEWPORT_HPP

#include "objects/Window.hpp"

class Viewport {
public:
        // Data
        int x;
        int y;
        unsigned int width;
        unsigned int height;

        float scale_x;
        float scale_y;

        // Methods
        Viewport(int x, int y, unsigned int width, unsigned int height);
        ~Viewport();
        bool its_on_screen(SDL_Rect position);
        SDL_Rect transform(SDL_Rect pos);
};

#endif
