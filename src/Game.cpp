#include "Game.hpp"

Game::Game() {
	running = false;
}

Game::~Game() {

}

void Game::start(const char *title, int x, int y, int width, int height, bool fullscreen) {
	// Create window and viewport
	window = new Window(title, x, y, width, height, fullscreen);

	// Load textures
	window->load_texture("assets/texture_atlas.png");

	// Create board
	board = new Board(new Viewport(0, 0, width, height));

	running = true;
}

void Game::handle_events() {
	SDL_Event event;

	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			running = false;

		} else if (event.type == SDL_KEYDOWN){
			switch (event.key.keysym.sym) {
				case SDLK_UP:
					board->viewport->y -= 5;
					break;

				case SDLK_DOWN:
					board->viewport->y += 5;
					break;

				case SDLK_LEFT:
					board->viewport->x -= 5;
					break;

				case SDLK_RIGHT:
					board->viewport->x += 5;
					break;
			}
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
