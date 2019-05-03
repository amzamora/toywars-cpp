#include <iostream>

#include "objects/game_objects/Water.hpp"

Water::Water(int row, int column) {
        this->row = row;
        this->column = column;
}

Water::~Water() {

}

void Water::draw(Window *window) {
        window->render(texture, cx, cy, tw, th, column * 64, row * 64, 64, 64);
}

void Water::update() {

}
