#include "item.h"
#include <istream>
#include <ostream>
#include <iostream>

Item::Item(Product& product, int quantity): _product{product}, _quantity{quantity} {}

Item::Item(std::istream& ist) {
    std::getline(ist, _quantity);
    while(ist) {
        ist>>_quantity;
    }
}
double Item::subtotal(){

	double num = (_product->price) * (_quantity);
	return num;
}


void Item::save(std::ostream& ost) {
    ost << _product._name << '\n';
    ost << _products.size() << '\n';
    for(Product* p : _products) p->save(ost);
    ost << _customers.size() << '\n';
    for(Customer* c : _customers) c->save(ost);
}



 
