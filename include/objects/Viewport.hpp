#ifndef VIEWPORT_HPP
#define VIEWPORT_HPP

#include "objects/Window.hpp"
#include "objects/Board.hpp"

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
        void draw(Window *window, Board *board);
};

#endif
