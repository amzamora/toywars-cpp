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
	dest.w = 64;
	dest.h = 64;

	for (int row = 0; row < 10; row++) {
		for (int column = 0; column < 10; column++) {
			bool draw = true;

			switch (board[row][column]) {
				case 1:
					src.x = 0;
					break;
				case 2:
					src.x = 128;
					break;
				case 3:
					src.x = 256;
					break;
				case 4:
					src.x = 384;
					break;
				default:
					draw = false;
			}

			if (draw) {
				dest.x = column * 64;
				dest.y = row * 64;

				TextureManager::draw(renderer, texture_atlas, src, dest);
			}
		}
	}
}
