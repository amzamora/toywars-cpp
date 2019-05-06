#ifndef Game_hpp
#define Game_hpp

#include "objects/Window.hpp"
#include "objects/Board.hpp"
#include "objects/Viewport.hpp"

class Game {
public:
	// Data
	bool running;
	unsigned int rows_amount;
	unsigned int columns_amount;

	// Objects
	Window *window;
	Board *board;
	Viewport *viewport;

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
