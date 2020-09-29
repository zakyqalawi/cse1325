#ifndef GATE_H
#define GATE_H
#include<iostream>
 
class Gate{

public:
typedef int Signal;
typedef int Pin;
Gate(Signal input1, Signal input2);
void connect(Gate& gate, Pin input_pin); // assigns the parameters to the corresponding attributes

Signal input(Pin pin, Signal signal);// int input

Signal input(Pin pin);// returns the signal of the pin inputed

Signal output(); // int output;
 
protected:
Signal _input1;
Signal _input2;
private:
Gate* _to_gate;
Pin _to_pin;
};

#endif
