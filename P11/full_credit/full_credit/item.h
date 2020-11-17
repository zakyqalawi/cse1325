#ifndef __ITEM_H
#define __ITEM_H

#include "tool.h"
#include "plant.h"
#include "mulch.h"
#include "customer.h"
#include "product.h"
#include <vector>

class Item {
  public:
    Item(Product& product, int quantity);
	Store(std::istream& ist);
	void save(std::ostream& ost);

    double subtotal();


  private:
   Product* _product;
	int _quantity;

};

#endif 
