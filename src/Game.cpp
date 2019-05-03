#include "Game.hpp"

Game::Game() {
	running = false;
}

Game::~Game() {

}

void Game::start(const char *title, int x, int y, int width, int height, bool fullscreen) {
	// Create window
	window = new Window(title, x, y, width, height, fullscreen);

	// Load textures
	window->load_texture("assets/texture_atlas.png");

	// Create board
	board = new Board();

	running = true;
}

void Game::handle_events() {
	SDL_Event event;

	while (SDL_PollEvent(&event) != 0) {
		switch (event.type) {
			case SDL_QUIT:
				running = false;
				break;
			default:
				break;
		}
	}
}

void Game::update() {

}

void Game::render() {
	// Clear display
	window->clear();

	// Draw board
	board->draw(window);

	//Update screen
	window->update();
}

void Game::close() {
	window->close();
	SDL_Quit();
}
