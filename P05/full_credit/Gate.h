#ifndef GATE_H
#define GATE_H
#include<iostream>
 
class Gate{

public:
typedef int Signal;
typedef int Pin;
//Gate(Signal input1, Signal input2);
Gate();
void connect(Gate& gate, Pin input_pin); // assigns the parameters to the corresponding attributes
void input(Pin pin, Signal signal);// assigns the signal to pin provided

Signal input(Pin pin);// returns the signal of the pin inputed

virtual Signal output()=0; // Output can be overridden
 
protected: // protected attributes
Signal _input1 =2;
Signal _input2 =3;


private: // private attributes
Gate* _to_gate =NULL;
Pin _to_pin;
};

#endif
