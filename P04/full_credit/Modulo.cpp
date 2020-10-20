#include "Modulo.h"





Modulo& Modulo::operator++(){// pre-increment
++_value; //increase value by 1
if(_value>_modulo||_value==_modulo){
	_value = _offset;
}
	return *this;

}

Modulo Modulo::operator++(int ){ // post-increment ++m
Modulo modulo{*this};
++*this;
return modulo;
}

void Modulo::set_nmsd(Modulo*nmsd){
*_nmsd = *nmsd;
}

int Modulo::compare(int Modulo& rhs){
if(_value <rhs._value) return -1;
if(_value >rhs._value) return 1;
if(_modulo <rhs._modulo) return -1;
if(_modulo >rhs._modulo) return 1;
if(_offset <rhs._offset) return -1;
if(_offset <rhs._offset) return 1;
return 0;
}

//Modulo Modulo::operator++(){


//std: 



//std::ostream& operator<<(std::ostream& ost, const Modulo& m){
//ost<<m._value;
//return ost;


