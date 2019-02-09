#include "TextureManager.hpp"

SDL_Texture* TextureManager::load_texture(SDL_Renderer* renderer, const char *filename) {
	SDL_Surface *temp_surface = IMG_Load(filename);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
	SDL_FreeSurface(temp_surface);

	return texture;
}
