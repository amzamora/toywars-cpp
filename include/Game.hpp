#ifndef Game_hpp
#define Game_hpp

#include "Window.hpp"
#include "Viewport.hpp"
#include "Input.hpp"
#include "play_screen/Board.hpp"

class Game {
public:
	// Data
	bool running;

	// Objects
	Window *window;
	Board *board;
	Input *input;

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
