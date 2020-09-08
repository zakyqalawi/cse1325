 #include <iostream>
#include<ctime>

int main(){
srand(time(NULL));
int num_die, num_face, num_rolls,i,sum,j;


std::cout<< "How many dice will be rolled? "<<std::endl;
std::cin>>num_die;

std::cout<< "How many faces will there be per dice? "<<std::endl;
std::cin>>num_face;

std::cout<< "How many times will the dice be rolled? "<<std::endl;
std::cin>>num_rolls;

int num[num_die];



for(i=0; i<num_rolls; i++){
sum=0;

std::cout<<"\nRoll "<<i<<": ";

for(j=0; j<num_die; j++){

num[j]=(rand()%6+1);
std::cout<<num[j]<<" ";
sum = sum+num[j];
}
std::cout<<"Sum: "<<sum;
std::cout<<"\n";

}


}
