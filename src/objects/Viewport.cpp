#include "objects/Viewport.hpp"

Viewport::Viewport(int x, int y, unsigned int width, unsigned int height) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;

        this->scale_x = 0;
        this->scale_y = 0;
}

Viewport::~Viewport() {

}

void Viewport::draw(Window *window, Board *board) {
        for (unsigned int i = 0; i < board->objects.size(); i++) {
                board->objects[i]->draw(window);
        }
}
