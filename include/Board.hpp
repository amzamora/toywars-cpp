#ifndef Board_hpp
#define Board_hpp

#include "SDL2/SDL.h"
#include <vector>

//#include "GameObject.hpp"

class Board {
	public:
		Board();
		~Board();
		void load_board(int board[10][10]);
		void draw();

	private:
		SDL_Texture *texture_atlas;
		//std::vector<GameObject*> game_objects;
};
#endif
