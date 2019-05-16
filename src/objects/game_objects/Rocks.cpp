#include <iostream>

#include "objects/game_objects/Rocks.hpp"

Rocks::Rocks(int row, int column) {
        this->row = row;
        this->column = column;
}

Rocks::~Rocks() {

}

void Rocks::draw(Window *window, SDL_Rect dst) {
        SDL_Rect clip;
        clip.x = cx;
        clip.y = cy;
        clip.w = tw;
        clip.h = th;

        window->render(texture, clip, dst);
}

void Rocks::update() {

}
