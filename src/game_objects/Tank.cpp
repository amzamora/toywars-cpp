#include "game_objects/Tank.hpp"
#include "Game.hpp"

#include <iostream>

Tank::~Tank() {}

void Tank::draw() {
	SDL_Rect clip = {texture_x, texture_y, width, height};
	SDL_Rect render_clip = {column * height, row * width, width, height};

	SDL_RenderCopy(Game::renderer, Game::texture_atlas, &clip, &render_clip);
}
