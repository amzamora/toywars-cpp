#include "Game.hpp"

Game *game = nullptr;

int main (int argc, const char *argv[]) {

	game = new Game();
	game->start("Toywars", 100, 100, 500, 200, false);

	while (game->running()) {
		game->handle_events();
		game->update();
		game->render();
	}

	game->close();

	return 0;
}
