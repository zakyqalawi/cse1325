 #include "tile.h"
#include<iostream>

int Tile::_width = -1;

std::string Tile::_blank="----";

Tile::Tile(std::string word){
         
_word = word;
_matched = false;

if(word.size() > _width){ // checks to see if the new word is longer than the previous

_width = word.size();
}
}

std::string Tile::word(){
return _word;
}

void Tile::set_matched(){
_matched=false;
}

bool Tile::match( Tile &tile){
if(_word != tile.word() ) {

        tile.set_matched();
}
        return _matched;
}

int Tile::width(){
return _width;
}

bool Tile::matched(){
return _matched;
}

std::string Tile::to_string(){
if(_matched) {
return _blank;}
else{
return _word;
}}



