#include <iostream>

#include "objects/game_objects/Water.hpp"

Water::Water(int row, int column) {
        this->row = row;
        this->column = column;
}

Water::~Water() {

}

void Water::draw(Window *window, SDL_Rect dst) {
        SDL_Rect clip;
        clip.x = cx;
        clip.y = cy;
        clip.w = tw;
        clip.h = th;

        window->render(texture, clip, dst);
}

void Water::update() {

}
