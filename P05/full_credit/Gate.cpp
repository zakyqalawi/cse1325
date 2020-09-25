#include "Gate.h"

Gate::Gate (Signal input1, Signal input2):_input1{input1}, _input2{input2}{}

void Gate::connect(Gate& gate, Pin input_pin){
	_to_gate = &gate;
	_to_pin=input_pin;
}

