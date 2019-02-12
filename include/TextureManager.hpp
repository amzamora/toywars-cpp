#include "Game.hpp"

class TextureManager {
	public:
		static SDL_Texture* load_texture(const char *filename);
		static void draw(SDL_Texture *texture, SDL_Rect source, SDL_Rect destination);
};
