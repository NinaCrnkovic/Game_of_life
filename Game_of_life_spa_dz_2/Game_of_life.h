#pragma once

#include <string>

using namespace std;

class Game_of_life
{
private:
	static const unsigned int COL = 90; 
	static const unsigned int ROW = 25; 
	bool _gen[COL][ROW];
	bool _next_gen[COL][ROW];
	bool rand_numb(int min, int max); 
	bool cell_taken(int i, int j); 
	int num_of_neighbors(int i, int j); 
	void init(); 

public:
	Game_of_life(); 
	void next_gen(); 
	void draw();
};

