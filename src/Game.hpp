#ifndef Game_hpp
#define Game_hpp

#include "Window.hpp"
#include "play_screen/Board.hpp"
#include "Viewport.hpp"
#include "Input.hpp"

enum GameState {
	TITLE_SCREEN,
	PLAY_SCREEN
};

class Game {
public:
	// Data
	bool running;
	enum GameState state = PLAY_SCREEN;

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
