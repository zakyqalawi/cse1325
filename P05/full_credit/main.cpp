#include"Gate.h"
#include"and.h"

int main(){

Gate test(0,1);

std::cout<<test.input(1)<<test.input(2)<<std::endl;

test.input(1,5);
std::cout<<test.input(1)<<test.input(2)<<std::endl;

test.input(2,5);
std::cout<<test.input(1)<<test.input(2)<<std::endl;


test.input(1,0);
std::cout<<test.input(1)<<test.input(2)<<std::endl;

Gate test2(1,1);

test.connect(test2,1);

test.input(1,0);
std::cout<<test.input(1)<<test.input(2)<<std::endl;
std::cout<<test.output()<<std::endl;

return 0;
}


