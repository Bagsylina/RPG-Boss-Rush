#ifndef OOP_CONSUMABLE_H
#define OOP_CONSUMABLE_H
#include <string>
#include <iostream>
#include "Item.h"

class Consumable : public Item{
    int HP_heal, MP_heal;
public:
    //constructor
    Consumable(const std::string& _name = "Food", const int _HP_heal = 0, const int _MP_heal = 0): Item(_name), HP_heal(_HP_heal), MP_heal(_MP_heal) {}
    Item* clone() const override {return new Consumable(*this);}

    //citire si afisare
    friend std::istream& operator>>(std::istream&, Consumable&);

    friend std::ostream& operator<<(std::ostream&, const Consumable&);

    void print(std::ostream&) const override;

    int itemType() const override;

    //getters
    int get_HP_heal() const;
    int get_MP_heal() const;
};


#endif //OOP_CONSUMABLE_H
