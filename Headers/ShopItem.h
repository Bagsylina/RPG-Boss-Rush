#ifndef OOP_SHOPITEM_H
#define OOP_SHOPITEM_H
#include "Item.h"

class ShopItem{
    Item* product;
    int cost, min_level;

public:
    explicit ShopItem(Item* sproduct, int scost = 1, int smin_level = 1): cost(scost), min_level(smin_level){
        product = sproduct->clone();
    }
    ShopItem(const ShopItem& other): cost(other.cost), min_level(other.min_level){
        product = other.product->clone();
    }
    ~ShopItem(){delete product;}
    ShopItem& operator = (const ShopItem&);

    //getters
    Item* get_product() const;
    int get_cost() const;
    int get_min_level() const;
};



#endif //OOP_SHOPITEM_H
