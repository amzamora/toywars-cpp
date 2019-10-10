#include "objects/Board.hpp"

#include "objects/Board.hpp"
#include "objects/game_objects/Tank.hpp"
#include "objects/game_objects/Water.hpp"
#include "objects/game_objects/Rocks.hpp"

Board::Board(Viewport *viewport) {
	this->viewport = viewport;

	int board[10][10] = {
		{0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 2, 2, 0, 0, 2, 3, 0, 0},
		{0, 0, 2, 0, 0, 0, 0, 3, 0, 0},
		{0, 0, 0, 0, 3, 3, 0, 0, 0, 0},
		{0, 0, 0, 0, 3, 3, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 3, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 3, 0, 0},
		{0, 0, 2, 2, 0, 0, 0, 0, 0, 0},
		{0, 0, 2, 2, 0, 0, 0, 1, 1, 2}
	};

	// Put objects on board
	for (int row = 0; row < 10; row++) {
		for (int column = 0; column < 10; column++) {
			if (board[row][column] == 1) {
				this->board[row][column] = new Tank(LEFT);

			} else if (board[row][column] == 2) {
				this->board[row][column] = new Water();

				if (row == 0 || board[row - 1][column] != 2) {
					((Water*) this->board[row][column])->topmost = true;
				}

			} else if (board[row][column] == 3) {
				this->board[row][column] = new Rocks();

			} else {
				this->board[row][column] = nullptr;
			}
		}
	}
}

Board::~Board() {

}

void Board::update(Input *input) {
	viewport->update(input);

	// Determine corresponding tile to mouse
	float nw = this->viewport->width * this->viewport->scale;
	float nh = this->viewport->height * this->viewport->scale;
	float diff_w = this->viewport->width - nw;
	float diff_h = this->viewport->height - nh;

	mouse_tile_x = (input->mouse_x + this->viewport->x - diff_w / 2) / (this->tile_size * this->viewport->scale);
	mouse_tile_y = (input->mouse_y + this->viewport->y - diff_h / 2) / (this->tile_size * this->viewport->scale);

	if (input->left_button_down && this->board[mouse_tile_y][mouse_tile_x] != nullptr && this->dragged_unit == nullptr) {
		if (this->board[mouse_tile_y][mouse_tile_x]->type == TANK) {
			this->dragged_unit = this->board[mouse_tile_y][mouse_tile_x];
		}
	}

	if (this->dragged_unit != nullptr) {
		if (!input->left_button_down) {
			this->dragged_unit = nullptr;
		} else {
			if (this->board[mouse_tile_y][mouse_tile_x] != this->dragged_unit) {
				if (this->board[mouse_tile_y][mouse_tile_x] == nullptr) {
					// Find element a removed it in board
					for (int row = 0; row < 10; row++) {
						for (int column = 0; column < 10; column++) {
							if (board[row][column] == dragged_unit) {
								this->board[row][column] = nullptr;
							}
						}
					}

					// Put element in new location
					this->board[mouse_tile_y][mouse_tile_x] = this->dragged_unit;

				} else {
					this->dragged_unit = nullptr;
				}
			}
		}
	}
}

void Board::draw(Window *window) {
	// Draw selection
	//if (board[this->mouse_tile_y][this->mouse_tile_x] != nullptr) {
		//if (board[this->mouse_tile_y][this->mouse_tile_x]->type != TANK) {
			SDL_Rect clip;
			clip.x = 0;
			clip.y = 224;
			clip.w = 32;
			clip.h = 32;

			SDL_Rect dst;
			dst.x = this->mouse_tile_x * tile_size;
			dst.y = this->mouse_tile_y * tile_size;
			dst.w = tile_size;
			dst.h = tile_size;

			window->draw("assets/atlas.png", clip, dst);
		//}
	//}

	// Draw objects
	for (int row = 0; row < 10; row++) {
		for (int column = 0; column < 10; column++) {
			if (board[row][column] != NULL) {
				board[row][column]->draw(window, get_object_position(row, column));
			}
		}
	}
}

SDL_Rect Board::get_object_position(int row, int column) {
	SDL_Rect pos;
	pos.x = column * tile_size;
	pos.y = row * tile_size;
	pos.w = tile_size;
	pos.h = tile_size;

	return pos;
}
