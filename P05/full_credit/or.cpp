  #include"or.h"


Or::Or() {}

Or::Signal Or::output(){
Signal check =0;
if(_input1 == 1&&_input2 ==1){
	check = 1;
}
 return check;
}

