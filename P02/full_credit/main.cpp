 #include <iostream>

int main(){

int num_die, num_face, num_rolls;

std::cout<< "How many dice will be rolled? "<<std::endl;
std::cin>>num_die;

std::cout<< "How many faces will there be per dice? "<<std::endl;
std::cin>>num_face;

std::cout<< "How many times will the dice be rolled? "<<std::endl;
std::cin>>num_rolls;

std::cout<<" number of dice: "<<num_die<<std::endl;

std::cout<<" number of faces: "<<num_face<<std::endl;

std::cout<<" number of rolls: "<<num_rolls<<std::endl;
}