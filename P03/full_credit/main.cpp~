
#include "tile.h"
#include "board.h"

int main(){

int num,num1, num2;

std::cout<<" Enter the number of words: ";
std::cin>>num;

Board b(num);

while(!b.solved()){
b.to_string();
std::cout<<" select unmatched tile 1: ";
std::cin>>num1;
std::cout<<" select unmatched tile 2: ";
std::cin>>num2;

b.attempt(num1-1, num2-1);
}
b.to_string();
return 0;
}




