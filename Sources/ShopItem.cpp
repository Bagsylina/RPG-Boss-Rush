#include "../Headers/ShopItem.h"

template <typename T>
ShopItem<T>::ShopItem(T* sproduct, const int scost, const int smin_level) : cost(scost), min_level(smin_level){
    if(cost < 0 || min_level < 0)
        throw InvalidData("Invalid shop item data.\n");
    product = sproduct->clone();
}

template <typename T>
ShopItem<T>::~ShopItem() {delete product;}

template <typename T>
ShopItem<T>& ShopItem<T>::operator = (const ShopItem<T>& other){
    if(this != &other) {
        delete product;
        product = other.product->clone();
        cost = other.cost;
        min_level = other.min_level;
    }
    return *this;
}

template <typename T>
T* ShopItem<T>::get_product() const{return product;}

template <typename T>
int ShopItem<T>::get_cost() const{return cost;}

template <typename T>
int ShopItem<T>::get_min_level() const{return min_level;}

template class ShopItem<Item>;
