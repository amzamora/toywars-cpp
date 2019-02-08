#ifndef Game_hpp
#define Game_hpp

#include "SDL2/SDL.h"
#include <cstdio>

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

	private:
		bool is_running;
		SDL_Window *window;
		SDL_Renderer *renderer;
};

#endif
