#include "Gate.h"


Gate::Gate ():_input1{0}, _input2{0}{}

//Gate::Gate();

void Gate::connect(Gate& gate, Pin input_pin){
	_to_gate = &gate;
	_to_pin=input_pin;
}

Gate::Signal Gate::input(Pin pin){ // returns the signal value of the pin

	if(pin == 1){
		return _input1;
				}
	return _input2;
}

void Gate::input(Pin pin, Signal signal){
	if(pin == 1){
		_input1 = signal;;
	if(_to_gate!=NULL){
	_to_gate->input(_to_pin, output());
	
}			

}
	else{
		_input2=signal;
	if(_to_gate!=NULL){
	_to_gate->input(_to_pin, output());

}			

		}
}


/*Gate::Signal Gate::output(){
 return 0;}/*{

Signal check =0;
return check;
}*/


