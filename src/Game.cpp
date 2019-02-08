#include "Game.hpp"
#include <cstdlib>

Game::Game() {

}

Game::~Game() {

}

void Game::start(const char *title, int x, int y, int width, int height, bool fullscreen) {
	// Initialize variables
	is_running = false;
	window = nullptr;
	renderer = nullptr;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	// Create window
	int flags = 0;
	if (fullscreen) flags = SDL_WINDOW_FULLSCREEN;
	window = SDL_CreateWindow(title, x, y, width, height, flags);

	if (window == NULL) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	is_running = true;
}

void Game::handle_events() {
	SDL_Event event;

	while (SDL_PollEvent(&event) != 0) {
		switch (event.type) {
			case SDL_QUIT:
				is_running = false;
				break;
			default:
				break;
		}
	}
}

void Game::update() {

}

void Game::render() {

}

void Game::close() {
	 SDL_DestroyWindow(window);
	 SDL_Quit();
}
