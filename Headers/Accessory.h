//
// Created by Anghel Fabian on 19/04/2023.
//

#ifndef OOP_ACCESSORY_H
#define OOP_ACCESSORY_H
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"

class Accessory : public Item{
    int type_buff;
    double buff_percentage;

public:
    //constructor
    Accessory(const std::string& _name = "Basic Ring", const int _type_buff = 0, const double _buff_percentage = 0): Item(_name), type_buff(_type_buff), buff_percentage(_buff_percentage){}
    //citire si afisare
    friend std::istream& operator>>(std::istream& in, Accessory& a)
    {
        in >> a.name >> a.type_buff >> a.buff_percentage;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Accessory& a)
    {
        return out << a.name << '\n' << Types[a.type_buff] << " buffed by " << 100 * a.buff_percentage << '%';
    }

    int itemType() override{return 2;}

    //getters
    int get_type() const;
    double get_buff() const;
};


#endif //OOP_ACCESSORY_H
