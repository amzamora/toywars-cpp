#include "Board.hpp"
#include "TextureManager.hpp"

Board::Board(SDL_Renderer *renderer) {
	// Load texture atlas
	texture_atlas = TextureManager::load_texture(renderer, "assets/texture_atlas.png");
}

void Board::draw(SDL_Renderer *renderer) {
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = 128;
	src.h = 128;

	SDL_Rect dest;
	dest.x = 0;
	dest.y = 0;
	dest.w = 128;
	dest.h = 128;

	TextureManager::draw(renderer, texture_atlas, src, dest);
}
