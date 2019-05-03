#include <iostream>

#include "objects/game_objects/Tank.hpp"

Tank::Tank(int row, int column) {
        this->row = row;
        this->column = column;
}

Tank::~Tank() {

}

void Tank::draw(Window *window) {
        window->render(texture, cx, cy, tw, th, column * 64, row * 64, 64, 64);
}

void Tank::update() {

}
