#ifndef __ITEM_H
#define __ITEM_H

#include "product.h"
#include <iostream>

class Item {
  public:
    Item(Product& product, int quantity);
	Item(std::istream& ist);
	void save(std::ostream& ost);
     friend std::ostream& operator<<(std::ostream& ost, const Item& item);
    double subtotal();


  private:
   Product* _product;
	int _quantity;

};

#endif 
