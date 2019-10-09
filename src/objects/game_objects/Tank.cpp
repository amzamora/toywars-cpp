#include <iostream>

#include "objects/game_objects/Tank.hpp"

Tank::Tank() {
	this->type = TANK;
}

Tank::~Tank() {

}

void Tank::draw(Window *window, SDL_Rect dst) {
	SDL_Rect clip;
	clip.x = cx;
	clip.y = cy;
	clip.w = tw;
	clip.h = th;

	window->draw(texture, clip, dst);
}

void Tank::update() {

}
