#include "objects/Board.hpp"
#include "objects/game_objects/Tank.hpp"


Board::Board() {
        Tank *tank = new Tank(0, 2);
        objects.push_back(tank);
}

Board::~Board() {

}

void Board::draw(Window *window) {
        for (unsigned int i = 0; i < objects.size(); i++) {
                objects[i]->draw(window);
        }
}
