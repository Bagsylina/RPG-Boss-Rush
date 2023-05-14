#ifndef OOP_SHOPITEM_H
#define OOP_SHOPITEM_H
#include "Item.h"

class ShopItem{
    Item* product;
    int cost, min_level;

public:
    explicit ShopItem(Item* sproduct, int scost = 1, int smin_level = 1): product(sproduct), cost(scost), min_level(smin_level) {}
    //~ShopItem(){delete product;}

    //getters
    Item* get_product() const;
    int get_cost() const;
    int get_min_level() const;
};



#endif //OOP_SHOPITEM_H
