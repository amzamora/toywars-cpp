#ifndef Game_hpp
#define Game_hpp

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Board.hpp"

class Game {
	public:
		Game();
		~Game();

		void start(const char *title, int x, int y, int width, int height, bool fullscreen);

		void handle_events();
		void update();
		void render();
		void close();

		bool running() { return is_running; }

		static SDL_Renderer* renderer;

	private:
		bool is_running;
		SDL_Window *window;
		Board *board;
};

#endif
