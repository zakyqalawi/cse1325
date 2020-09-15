 #include<iostream>
#include<string>
#include"tile.h"
#include"board.h"
#include<algorithm>

Board::Board(int tiles){

std::vector<std::string> words {
"bang", "beam", "bear", "cafe", "came",
"cold", "come", "cool", "date", "diet",
"door", "doth", "echo", "exes", "exit",
"face", "fame", "feed", "fire", "five",
"four", "free", "frog", "from", "game",
"goes", "good", "grit", "have", "heal",
"hear", "here", "hide", "hole", "home",
"hope", "huge", "keep", "kill", "lace",
"lame", "leek", "life", "live", "maps",
"mass", "mate", "maze", "move", "near",
"need", "nine", "once", "quit", "ques",
"race", "read", "reed", "reef", "rice",
"roof", "sins", "stay", "tame", "teen",
"tens", "tide", "tied", "tree", "twin",
"zero", "zips",
};

for( int i=0; i<tiles; i++){
    for(int j=0; j<2; j++){
       _tiles.push_back(Tile(words[i]));}
}

random_shuffle(_tiles.begin(), _tiles.end());

for(auto & v: _tiles){
std::cout<<v.word()<<std::endl;
}}

std::string Board::attempt(int tile1, int tile2){
bool matched = _tiles[tile1].match(_tiles[tile2]);
return _tiles[tile1].to_string();
}

bool Board::solved(){
int check =0; 
for( auto v: _tiles){
if(v.matched()==false) check++; }
return check;
}


void Board::to_string(){

int count = 1;
for(auto & v: _tiles){
std::cout<<count<<")"<<v.to_string()<<std::endl;
count++;
}}








