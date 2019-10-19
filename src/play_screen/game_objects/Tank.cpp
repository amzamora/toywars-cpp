#include <iostream>

#include "Tank.hpp"

Tank::Tank(enum Direction direction) {
	this->type = TANK;
	this->direction = direction;
}

Tank::~Tank() {

}

void Tank::draw(Window *window, SDL_Rect dst) {
	SDL_Rect clip;
	clip.x = cx;
	clip.w = tw;
	clip.h = th;

	switch (this->direction) {
		case RIGHT:
			clip.y = rcy;
			break;
		case LEFT:
			clip.y = lcy;
			break;
		case UP:
			clip.y = tcy;
			break;
		case DOWN:
			clip.y = dcy;
			break;
		default:
			break;
	}

	window->draw(texture, clip, dst);
}

void Tank::update() {

}
