#include <iostream>

#include "objects/game_objects/Tank.hpp"

Tank::Tank(int row, int column) {
        this->row = row;
        this->column = column;
}

Tank::~Tank() {

}

void Tank::draw(Window *window, SDL_Rect dst) {
        SDL_Rect clip;
        clip.x = cx;
        clip.y = cy;
        clip.w = tw;
        clip.h = th;

        window->render(texture, clip, dst);
}

void Tank::update() {

}
