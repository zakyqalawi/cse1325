 #ifndef BOARD_H
#define BOARD_H

#include<string>
#include<iostream>
#include<vector>
#include "tile.h"
#include<algorithm>

class Board{

public:
Board(int tiles);
std::string attempt( int tile1, int tile2);
bool solved();
void to_string();

private:
 std::vector<Tile> _tiles;
};




#endif
