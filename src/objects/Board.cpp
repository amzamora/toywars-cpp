#include "objects/Board.hpp"
#include "objects/game_objects/Tank.hpp"
#include "objects/game_objects/Water.hpp"
#include "objects/game_objects/Rocks.hpp"

Board::Board() {
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
