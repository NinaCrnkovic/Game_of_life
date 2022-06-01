#include <iostream>
#include <string>
#include "Game_of_life.h"
#include <ctime>


using namespace std;

int main() {
	srand(time(nullptr));
	Game_of_life game;

	bool next;

	do {

		game.draw();



		cout << endl << endl << "Next (1/0): ";
		cin >> next;
		system("CLS");
	} while (next);

	return 0;
}