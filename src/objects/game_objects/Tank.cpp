#include <iostream>

#include "objects/game_objects/Tank.hpp"

Tank::Tank(int column, int row) {
        this->column = column;
        this->row = row;
}

Tank::~Tank() {

}

void Tank::draw(Window *window) {
        window->render(texture, cx, cy, tw, th, column * 128, row * 128, 128, 128);
}

void Tank::update() {

}
