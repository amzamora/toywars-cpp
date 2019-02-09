#include "Game.hpp"

class TextureManager {
	public:
		static SDL_Texture* load_texture(SDL_Renderer* renderer, const char *filename);
};
