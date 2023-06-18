#ifndef OOP_SHOPITEM_H
#define OOP_SHOPITEM_H
#include "Item.h"

class ShopItem{
    Item* product;
    int cost, min_level;

public:
    explicit ShopItem(Item* sproduct, int scost = 1, int smin_level = 1);
    ShopItem(const ShopItem& other): cost(other.cost), min_level(other.min_level){
        product = other.product->clone();
    }
    ~ShopItem();
    ShopItem& operator = (const ShopItem&);

    //getters
    [[nodiscard]]Item* get_product() const;
    [[nodiscard]]int get_cost() const;
    [[nodiscard]]int get_min_level() const;
};

template <typename T>
class ShopItem1{
    T* product;
    int cost, min_level;
public:
    explicit ShopItem1(T* sproduct, int scost = 1, int smin_level = 1);
    ShopItem1(const ShopItem1<T>& other): cost(other.cost), min_level(other.min_level){
        product = other.product->clone();
    }
    ~ShopItem1();
    ShopItem1& operator = (const ShopItem1&);

    //getters
    [[nodiscard]]T* get_product() const;
    [[nodiscard]]int get_cost() const;
    [[nodiscard]]int get_min_level() const;
};

#endif //OOP_SHOPITEM_H
