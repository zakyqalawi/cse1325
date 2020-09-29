  #include"and.h"


And::And(Signal _input1, Signal _input2) {}


And::Signal And::output(){
Signal check =0;
if(_input1 == 1&&_input2 ==1){
	check = 1;
}
 return check;
}

