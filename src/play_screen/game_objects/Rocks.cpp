#include <iostream>

#include "play_screen/game_objects/Rocks.hpp"

Rocks::Rocks() {
	this->type = ROCKS;
}

Rocks::~Rocks() {

}

void Rocks::draw(Window *window, SDL_Rect dst) {
	SDL_Rect clip;
	clip.x = cx;
	clip.y = cy;
	clip.w = tw;
	clip.h = th;

	window->draw(texture, clip, dst);
}

void Rocks::update() {

}
