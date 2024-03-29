#include "objects/Viewport.hpp"

Viewport::Viewport(int x, int y, unsigned int width, unsigned int height) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;

        this->scale_x = 1.0;
        this->scale_y = 1.0;
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

void Viewport::update(Input *input) {
        if (input->left) {
                this->x -= 5;
        }

        if (input->right) {
                this->x += 5;
        }

        if (input->up) {
                this->y -= 5;
        }

        if (input->down) {
                this->y += 5;
        }
 }
