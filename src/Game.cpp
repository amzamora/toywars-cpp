#include "Game.hpp"

Game::Game() {
	running = false;
}

Game::~Game() {

}

void Game::start(const char *title, int x, int y, int width, int height, bool fullscreen) {
	// Create window and input
	window = new Window(title, x, y, width, height, fullscreen);
	input = new Input();

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

		} else if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
				case SDLK_UP:
					input->up = true;
					break;

				case SDLK_DOWN:
					input->down = true;
					break;

				case SDLK_LEFT:
					input->left = true;
					break;

				case SDLK_RIGHT:
					input->right = true;
					break;
			}

		} else if (event.type == SDL_KEYUP) {
			switch (event.key.keysym.sym) {
				case SDLK_UP:
					input->up = false;
					break;

				case SDLK_DOWN:
					input->down = false;
					break;

				case SDLK_LEFT:
					input->left = false;
					break;

				case SDLK_RIGHT:
					input->right = false;
					break;
			}

		} else if(event.type == SDL_MOUSEWHEEL) {
			if (event.wheel.direction == SDL_MOUSEWHEEL_FLIPPED) {
				event.wheel.y *= -1;
				event.wheel.x *= -1;
			}

			// Scroll up
			if(event.wheel.y > 0) {
				input->zoom_out = event.wheel.y;

			}

			// Scroll down
			else if(event.wheel.y < 0) {
				input->zoom_in = -event.wheel.y;
			}
		}

	}
}

void Game::update() {
	board->update(input);
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
}
