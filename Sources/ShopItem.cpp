#include "../Headers/ShopItem.h"

ShopItem::ShopItem(Item *sproduct, const int scost, const int smin_level) : cost(scost), min_level(smin_level){
    if(cost < 0 || min_level < 0)
        throw InvalidData("Invalid shop item data.\n");
    product = sproduct->clone();
}

ShopItem::~ShopItem() {delete product;}

ShopItem& ShopItem::operator = (const ShopItem& other){
    if(this != &other) {
        delete product;
        product = other.product->clone();
        cost = other.cost;
        min_level = other.min_level;
    }
    return *this;
}

Item* ShopItem::get_product() const{return product;}
int ShopItem::get_cost() const{return cost;}
int ShopItem::get_min_level() const{return min_level;}
