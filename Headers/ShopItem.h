#ifndef OOP_SHOPITEM_H
#define OOP_SHOPITEM_H
#include "Item.h"

class ShopItem{
    Item* product;
    int cost, min_level;

public:
    explicit ShopItem(Item* sproduct, int scost = 1, int smin_level = 1): cost(scost), min_level(smin_level){
        if(cost < 0 || min_level < 0)
            throw InvalidData("Invalid shop item data.\n");
        product = sproduct->clone();
    }
    ShopItem(const ShopItem& other): cost(other.cost), min_level(other.min_level){
        product = other.product->clone();
    }
    ~ShopItem(){delete product;}
    ShopItem& operator = (const ShopItem&);

    //getters
    [[nodiscard]]Item* get_product() const;
    [[nodiscard]]int get_cost() const;
    [[nodiscard]]int get_min_level() const;
};



#endif //OOP_SHOPITEM_H
