#include "Modulo.h"





Modulo& Modulo::operator++(){// pre-increment
}

Modulo Modulo::operator++(int ){ // post-increment ++m
Modulo modulo{*this};
++*this;
return modulo;
}

void Modulo::set_nmsd(Modulo*nmsd){
*_nmsd = *nmsd;
}

//Modulo Modulo::operator++(){


//std: 



//std::ostream& operator<<(std::ostream& ost, const Modulo& m){
//ost<<m._value;
//return ost;


