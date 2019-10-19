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

			// Scroll
			if(event.wheel.y != 0) {
				input->scroll += event.wheel.y;

			}

		} else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP )  {
			SDL_GetMouseState(&(input->mouse_x), &(input->mouse_y));

			if (event.type == SDL_MOUSEBUTTONDOWN) {
				if (event.button.button == SDL_BUTTON_LEFT) {
					input->left_button_down = true;
				}
			}

			if (event.type == SDL_MOUSEBUTTONUP) {
				if (event.button.button == SDL_BUTTON_LEFT) {
					input->left_button_down = false;
				}
			}

		}
	}
}

void Game::update() {
	switch (this->state) {
		case TITLE_SCREEN:
			break;

		case PLAY_SCREEN:
			board->update(input);
			input->scroll = 0;
			break;
	}
}

void Game::render() {
	switch (this->state) {
		case TITLE_SCREEN:
			// Clear display
			window->clear();

			break;

		case PLAY_SCREEN:
			// Clear display
			window->clear();

			// Draw board
			board->draw(window);

			//Update screen
			window->viewport = board->viewport;
			window->update();
			window->viewport = nullptr;

			break;

	}
}

void Game::close() {
	window->close();
	SDL_Quit();
}
