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
	if (topmost) {
		clip.x = topmost_cx;
		clip.y = topmost_cy;
		clip.w = topmost_w;
		clip.h = topmost_h;
	} else {
		clip.x = cx;
		clip.y = cy;
		clip.w = tw;
		clip.h = th;
	}

	window->draw(texture, clip, dst);
}

void Water::update() {

}
