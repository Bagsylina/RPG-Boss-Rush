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

template <typename T>
ShopItem1<T>::ShopItem1(T* sproduct, const int scost, const int smin_level) : cost(scost), min_level(smin_level){
    if(cost < 0 || min_level < 0)
        throw InvalidData("Invalid shop item data.\n");
    product = sproduct->clone();
}

template <typename T>
ShopItem1<T>::~ShopItem1() {delete product;}

template <typename T>
ShopItem1<T>& ShopItem1<T>::operator = (const ShopItem1<T>& other){
    if(this != &other) {
        delete product;
        product = other.product->clone();
        cost = other.cost;
        min_level = other.min_level;
    }
    return *this;
}

template <typename T>
T* ShopItem1<T>::get_product() const{return product;}

template <typename T>
int ShopItem1<T>::get_cost() const{return cost;}

template <typename T>
int ShopItem1<T>::get_min_level() const{return min_level;}

template class ShopItem1<Item>;
