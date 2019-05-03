#include <iostream>

#include "objects/game_objects/Rocks.hpp"

Rocks::Rocks(int row, int column) {
        this->row = row;
        this->column = column;
}

Rocks::~Rocks() {

}

void Rocks::draw(Window *window) {
        window->render(texture, cx, cy, tw, th, column * 64, row * 64, 64, 64);
}

void Rocks::update() {

}
