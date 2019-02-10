#include "Game.hpp"

Game *game = nullptr;
const Uint32 MS_PER_FRAME = 1000 / 60;

int main (int argc, const char *argv[]) {

	game = new Game();
	game->start("Toywars", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 512, 128, false);

	Uint32 start, elapsed;
	while (game->running()) {
		start = SDL_GetTicks();

		game->handle_events();
		game->update();
		game->render();

		elapsed = SDL_GetTicks() - start;
		if (MS_PER_FRAME > elapsed) {
			SDL_Delay(MS_PER_FRAME - elapsed);
		}
	}

	game->close();

	return 0;
}
