#include"Gate.h"
#include"and.h"
#include"or.h"

int main(){

And gate1; // initalizing 2 And gates whos outputs will feed into pins 1&2 of or gate
And gate2

Or gate3; // outputs of And gates come in as inputs

for(int i =0; i<2; i++){  // 4 nested loops will iterate 2 times each = 16 total trials
	for(int j =0; j<2; j++){
		for(int k =0; k<2; k++){
			for(int l =0; l<2; l++){
				gate1.input(1,i); // input of pin1 is going to equal i
				gate1.input(2,j);// input of pin1 is going to equal j
				gate1.input(1,k);// input of pin1 is going to equal k
				gate1.input(1,l);// input of pin1 is going to equal l
				
				gate1.connect(gate3,1); // connects the result of the first and gate to the input of or gate pin 1
				gate2.connect(gate3,2) // output of second gate becomes input of pin 2 of gate 3
}}}}
return 0;
}


