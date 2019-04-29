#ifndef Game_hpp
#define Game_hpp

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"


#include "objects/Window.hpp"

class Game {
public:
	// Data
	bool running;
	unsigned int rows_amount;
	unsigned int columns_amount;

	// Objects
	Window *window;
	//Board *board;
	//Viewport *viewport;

	// Methods
	Game();
	~Game();
	void start(const char *title, int x, int y, int width, int height, bool fullscreen);
	void handle_events();
	void update();
	void render();
	void close();
};

#endif
