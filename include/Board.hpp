#ifndef Board_hpp
#define Board_hpp

#include "SDL2/SDL.h"

class Board {
	public:
		Board(SDL_Renderer *renderer);
		~Board();
		//void load_board(int board[16][16]);
		void draw(SDL_Renderer *renderer);

	private:
		SDL_Texture *texture_atlas;

		int board[10][10] = {{1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		                     {2, 2, 0, 0, 0, 0, 0, 0, 0, 0},
		                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		                     {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
		                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		                     {0, 0, 0, 0, 0, 3, 0, 0, 0, 0},
		                     {0, 0, 0, 3, 4, 4, 0, 0, 0, 0},
		                     {0, 0, 1, 3, 4, 4, 0, 0, 0, 0},
		                     {0, 0, 0, 0, 4, 4, 0, 0, 0, 0}};


};
#endif
