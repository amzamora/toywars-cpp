#include "objects/Window.hpp"

Window::Window(const char *title, int x, int y, int width, int height, bool fullscreen) {
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
}

Window::~Window() {

}

void Window::clear() {
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
}

void Window::update() {
	SDL_RenderPresent(renderer);
}

void Window::close() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
