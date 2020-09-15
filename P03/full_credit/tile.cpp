 #include "tile.h"
#include<iostream>

int _width = -1;

tile::tile() : tile{""} { }

String::String(const char* _blank) {
    std::cerr << "### String(text)\n";
    _size = strlen(_blank);
    _text = new char[_size];
    strcpy(_text, text);
int tile::width(){
return _width;
}



