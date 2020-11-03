#include "store.h"
#include <istream>
#include <ostream>

Customer::Customer(std::string name, std::string phone, std::string email) : _name{name}, _phone{phone}, _email{email} {};


Customer::Customer(std::istream& ist) {
    std::getline(ist, _name);
    std::getline(ist, _phone);
	std::getline(ist, _email);
}

void Customer::save(std::ostream& ost) {
   ost<<_name<<_phone<<_email<<'\n'<<std::endl;
}