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

bool Viewport::its_on_screen(SDL_Rect position) {
        return true;
}

SDL_Rect Viewport::transform(SDL_Rect pos) {
        pos.x -= this->x;
        pos.y -= this->y;

        return pos;
}
