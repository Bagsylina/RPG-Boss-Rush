//
// Created by Anghel Fabian on 19/04/2023.
//

#ifndef OOP_SHOPITEM_H
#define OOP_SHOPITEM_H
#include "Item.h"

class ShopItem{
    Item* product;
    int cost, min_level;

public:
    explicit ShopItem(Item* _product, int _cost = 1, int _min_level = 1): product(_product), cost(_cost), min_level(_min_level) {}

    //getters
    Item* get_product() const{return product;}
    int get_cost() const{return cost;}
    int get_min_level() const{return min_level;}
};



#endif //OOP_SHOPITEM_H
