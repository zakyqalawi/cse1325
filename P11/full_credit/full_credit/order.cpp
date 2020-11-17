#include "order.h"
#include <istream>
#include <ostream>
#include <iostream>

Order::Order(Customer& customer): _customer{customer} {}

Order::Order(std::istream& ist) {
    std::getline(ist, _customer);
    while(ist) {
        ist>>_customer;
    }
}
double Order::total(){

	double num = 0;
	for(item c : _items){
	num = num+c;
} 

	return num;
}


void Order::save(std::ostream& ost) {
    ost << _product._name << '\n';
    ost << _products.size() << '\n';
    for(Product* p : _products) p->save(ost);
    ost << _customers.size() << '\n';
    for(Customer* c : _customers) c->save(ost);
}


 
