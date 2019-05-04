#ifndef VIEWPORT_HPP
#define VIEWPORT_HPP

#include "objects/Window"
#include "objects/Board"

class Viewport {
public:
        // Data
        int x = 0;
        int y = 0;
        const int width;
        const int height;

        float scale_x;
        float scale_y;

        // Methods
        void draw(Window *window, Board *board);
};

#endif
