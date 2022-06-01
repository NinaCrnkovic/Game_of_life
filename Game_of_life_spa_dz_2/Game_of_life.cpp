#include "Game_of_life.h"

#include <iostream>

bool Game_of_life::rand_numb(int min, int max)
{
	int num = rand() % (max - min + 1) + min;
	if (num <=25) {
		return true;
	}
	return false;
}

bool Game_of_life::cell_taken(int i, int j)
{
	if (this->_gen[i][j] == true) {
		return true;
	}

	return false;
}

int Game_of_life::num_of_neighbors(int i, int j)
{
	int neighbors = 0;

	for (int p = -1; p < 2; p++) {
		for (int r = -1; r < 2; r++) {

			int a = ((i + p + COL) % COL);
			int b = ((j + r + ROW) % ROW);

			if (this->_gen[a][b] == 1) {
				neighbors++;

			}
		}
	}
	return (neighbors - 1);
}

void Game_of_life::init()
{
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (rand_numb(1,100)) {
				this->_gen[i][j] = 1;

			}
			else {
				this->_gen[i][j] = 0;
			}
		}
	}


}

Game_of_life::Game_of_life()
{
	init();
}

void Game_of_life::next_gen()
{


	for (int i = 0; i < COL; i++) {
		for (int j = 0; j < ROW; j++) {
			if (cell_taken(i, j))

			{ // ALIVE
				if (num_of_neighbors(i, j) == 2 || num_of_neighbors(i, j) == 3) {
					this->_next_gen[i][j] = 1;

				}
				else {
					this->_next_gen[i][j] = 0;
				}

			}
			else if (cell_taken(i, j) == false)

			{ // DEAD
				if (num_of_neighbors(i, j) != 3) {
					this->_next_gen[i][j] = 0;
				}
				else if (num_of_neighbors(i, j) == 3) {
					this->_next_gen[i][j] = 1;
				}
			}

		}
	}
}

void Game_of_life::draw() {
	next_gen();
	for (int i = 0; i < ROW; i++) {
		cout << endl;
		for (int j = 0; j < COL; j++) {
			if (this->_gen[i][j]) {
				cout << "@";
			}
			else {
				cout << " ";
			}
			this->_gen[i][j] = this->_next_gen[i][j];
		}
	}

}
