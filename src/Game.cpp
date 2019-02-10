#include "Game.hpp"
#include "TextureManager.hpp"
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

	// Create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL) {
		printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	is_running = true;

	// Create board
	board = new Board(renderer);
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
	// Clear display
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);

	// Draw board
	board->draw(renderer);

	//Update screen
	SDL_RenderPresent(renderer);
}

void Game::close() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
