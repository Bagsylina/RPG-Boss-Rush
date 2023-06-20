#ifndef OOP_SHOPITEM_H
#define OOP_SHOPITEM_H
#include "Skill.h"

template <typename T>
class ShopItem{
    T* product;
    int cost, min_level;
public:
    explicit ShopItem(T* sproduct, int scost = 1, int smin_level = 1);
    ShopItem(const ShopItem<T>& other): cost(other.cost), min_level(other.min_level){
        product = dynamic_cast<T*>(other.product->clone());
        if(product == NULL)
            throw InvalidInput();
    }
    ~ShopItem();
    ShopItem& operator = (const ShopItem&);

    //getters
    [[nodiscard]]T* get_product() const;
    [[nodiscard]]int get_cost() const;
    [[nodiscard]]int get_min_level() const;
};

#endif //OOP_SHOPITEM_H
