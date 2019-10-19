#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
using namespace std;

#include "../Window.hpp"
#include "../Viewport.hpp"
#include "../Input.hpp"
#include "GameObject.hpp"

class Board {
public:
	// Data
	GameObject* board[10][10];
	GameObject* dragged_unit = nullptr;

	Viewport *viewport;
	unsigned int tile_size = 64;

	int mouse_tile_x = -1;
	int mouse_tile_y = -1;

	// Methods
	Board(Viewport *viewport);
	~Board();

	void update(Input *input);

	void draw(Window *window);
	SDL_Rect get_object_position(int row, int column);
};

#endif
