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
                {0, 0, 2, 2, 0, 0, 2, 3, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 3, 0, 0, 0, 0, 0},
                {0, 0, 0, 1, 3, 0, 0, 3, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 3, 0, 0},
                {0, 0, 2, 2, 0, 0, 0, 0, 0, 0},
                {0, 0, 2, 2, 0, 0, 0, 1, 1, 2}
        };

        for (int row = 0; row < 10; row++) {
                for (int column = 0; column < 10; column++) {
                        if (board[row][column] == 1) {
                                objects.push_back(new Tank(row, column));

                        } else if (board[row][column] == 2) {
                                objects.push_back(new Water(row, column));

                        } else if (board[row][column] == 3) {
                                objects.push_back(new Rocks(row, column));
                        }
                }
        }
}

Board::~Board() {

}

void Board::draw(Window *window) {
        for (unsigned int i = 0; i < objects.size(); i++) {
                if (viewport->its_on_screen(get_object_position(objects[i]))) {
                        objects[i]->draw(window, viewport->transform(get_object_position(objects[i])));
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
