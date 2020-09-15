#ifndef TILE_H
#define TILE_H
#include<string>
#include<iostream>
#include<string>



class tile{

public:// holds methods, constructers, and static methods
    tile();
    ~tile();
    int width(); // returns width
    std::string word();


private:// holds variables and static 

std::string _word;
bool _matched;
 static int _width;
static std::string blank;

};

#endif
