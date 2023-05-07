//
// Created by Anghel Fabian on 19/04/2023.
//

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
    //citire si afisare
    friend std::istream& operator>>(std::istream& in, Consumable& c)
    {
        in >> c.name >> c.HP_heal >> c.MP_heal;
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const Consumable& c)
    {
        out << c.name << "\n Heals ";
        if(c.MP_heal == 0)
            out << c.HP_heal << " HP";
        else if (c.HP_heal == 0)
            out << c.MP_heal << " MP";
        else
            out << c.HP_heal << " HP and " << c.MP_heal << " MP";
        return out;
    }

    int itemType(){return 4;}

    //getters
    int get_HP_heal() const;
    int get_MP_heal() const;
};


#endif //OOP_CONSUMABLE_H
