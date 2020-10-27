   
#include "store.h"
#include <istream>
#include <ostream>

Store::Store(std::string name ) : _name{name}  { }
void Store::add_product(const Tool& product) {_products.push_back(new Tool{product});}
void Store::add_product(const Plant& product) {_products.push_back(new Plant{product});}
void Store::add_product(const Mulch& product) {_products.push_back(new Mulch{product});}
int Store::products() {return _products.size();}
const Product& Store:: product(int index) {return *_products.at(index);}


Store::Store(std::istream& ist){
	//Product store;
	ist>> _name;
	//while(ist>> store) {_products.push_back(store);} // kept giving errors so I commmented it out
}
void Store::save(std::ostream& ost){
	ost<<_name<<'\n'<<std::endl;  // saves the name of the store to the file and creates a new line afterwards
	for(Product*product: _products){  // for loop that runs through all of the products availible
		product->save(ost); // calls the Product save method
}
}

