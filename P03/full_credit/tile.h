#ifndef TILE_H
#define TILE_H

#include<string>
#include<iostream>

class Tile{

public:// holds methods, constructers, and static methods
    Tile(std::string word);
    ~Tile();
    int width(); // returns width
    std::string word();
    void set_matched();
    bool match(Tile &tile);
    bool matched();
    std::string to_string();


private:// holds variables and static 

std::string _word;
bool _matched;
 static int _width;
static std::string _blank;

};

#endif
