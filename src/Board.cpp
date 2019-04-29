#include "Board.hpp"
#include "game_objects/Tank.hpp"

Board::Board() {
	// Load board
	int board[10][10] = {{1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
			     {2, 2, 0, 0, 0, 0, 0, 0, 0, 0},
			     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			     {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
			     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			     {0, 0, 0, 0, 0, 3, 0, 0, 0, 0},
			     {0, 0, 0, 3, 4, 4, 0, 0, 0, 0},
			     {0, 0, 1, 3, 4, 4, 0, 0, 0, 0},
			     {0, 0, 0, 0, 4, 4, 0, 0, 0, 0}};

	load_board(board);

}

void Board::load_board(int board[10][10]) {
	for (int row = 0; row < 10; row++) {
		for (int column = 0; column < 10; column++) {
			switch (board[row][column]) {
				case 1:
					game_objects.push_back(new Tank(row, column));
					break;
				case 2:
					//game_objects.push_back(GameObject::new_mountain(row, column));
					break;
				case 3:
					//game_objects.push_back(GameObject::new_lake(row, column));
					break;
				default:
					break;
			}
		}
	}
}

void Board::draw() {
	for (int i = 0; i < (int) game_objects.size(); i++) {
		game_objects[i]->draw();
	}
}
