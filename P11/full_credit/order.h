#ifndef __ORDER_H
#define __ORDER_H

#include "tool.h"
#include "plant.h"
#include "mulch.h"
#include "customer.h"
#include "product.h"
#include <vector>

class Order {
  public:
    Order(Customer& customer);
	Order(std::istream& ist);
	void save(std::ostream& ost);
	void add_item(Item item);
    double total();


  private:
   vector<item> _items;
	Customer _customer;

};

#endif  
