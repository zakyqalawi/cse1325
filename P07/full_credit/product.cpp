 #include "product.h"
#include <cmath>

Product::Product(std::string name, double price, std::string description)
    : _name{name}, _price{price}, _description{description}, _stocknum{++_nextsn} { }
std::string Product::to_string() const {
    return _name +'\n' + "Stock# " + std::to_string(_stocknum) +'\n'
                 + "$" + std::to_string(_price) + '\n'
                 + _description;
}
std::ostream& operator<<(std::ostream& ost, const Product& product) {
    ost << product.to_string();
    return ost;
}
int Product::_nextsn = 0;

void Product::save(std::ostream& ost){
	//ost<<_nextsn<<'\n'<<_stocknum<<'\n'<<to_string()<<'\n'<<_description<<'\n'<<std::endl;

		ost<<to_string()<<'\n'<<std::endl;
}


 
