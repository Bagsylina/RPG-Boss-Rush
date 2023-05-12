#ifndef OOP_SHOPITEM_H
#define OOP_SHOPITEM_H
#include "Item.h"

class ShopItem{
    Item* product;
    int cost, min_level;

public:
    explicit ShopItem(Item* _product, int _cost = 1, int _min_level = 1): product(_product), cost(_cost), min_level(_min_level) {}

    //getters
    Item* get_product() const;
    int get_cost() const;
    int get_min_level() const;
};



#endif //OOP_SHOPITEM_H
