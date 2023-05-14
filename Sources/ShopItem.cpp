#include "../Headers/ShopItem.h"

ShopItem& ShopItem::operator = (const ShopItem& other){
    if(product)
        delete product;
    product = other.product->clone();
    cost = other.cost;
    min_level = other.min_level;
    return *this;
}

Item* ShopItem::get_product() const{return product;}
int ShopItem::get_cost() const{return cost;}
int ShopItem::get_min_level() const{return min_level;}
