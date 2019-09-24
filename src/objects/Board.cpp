#include "objects/Board.hpp"

#include "objects/Board.hpp"
#include "objects/game_objects/Tank.hpp"
#include "objects/game_objects/Water.hpp"
#include "objects/game_objects/Rocks.hpp"

Board::Board(Viewport *viewport) {
        this->viewport = viewport;

        int board[10][10] = {
                {1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}
        };

        /*int board[10][10] = {
                {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 1, 2, 2, 0, 0, 2, 3, 0, 0},
                {0, 0, 2, 2, 0, 0, 2, 3, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 3, 0, 0, 0, 0, 0},
                {0, 0, 0, 1, 3, 0, 0, 3, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 3, 0, 0},
                {0, 0, 2, 2, 0, 0, 0, 0, 0, 0},
                {0, 0, 2, 2, 0, 0, 0, 1, 1, 2}
        };*/

        // Put objects on board
        for (int row = 0; row < 10; row++) {
                for (int column = 0; column < 10; column++) {
                        if (board[row][column] == 1) {
                                this->board[row][column] = new Tank(row, column);

                        } else if (board[row][column] == 2) {
                                this->board[row][column] = new Water(row, column);

                                if (row == 0 || board[row - 1][column] != 2) {
                                        ((Water*) this->board[row][column])->topmost = true;
                                }

                        } else if (board[row][column] == 3) {
                                this->board[row][column] = new Rocks(row, column);
                        } else {
                                this->board[row][column] = NULL;
                        }
                }
        }
}

Board::~Board() {

}

void Board::update(Input *input) {
        viewport->update(input);
}

void Board::draw(Window *window) {
        for (int row = 0; row < 10; row++) {
                for (int column = 0; column < 10; column++) {
                        if (board[row][column] != NULL) {
                                board[row][column]->draw(window, viewport->transform(get_object_position(board[row][column])));
                        }
                }
        }
}

SDL_Rect Board::get_object_position(GameObject *object) {
        SDL_Rect pos;
        pos.x = object->column * tile_size;
        pos.y = object->row * tile_size;
        pos.w = tile_size;
        pos.h = tile_size;

        return pos;
}
