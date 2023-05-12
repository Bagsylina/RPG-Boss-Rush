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
    Item* clone() const override {return new Accessory(*this);}

    //citire si afisare
    friend std::istream& operator>>(std::istream&, Accessory&);

    friend std::ostream& operator<<(std::ostream&, const Accessory&);

    void print(std::ostream&) const override;

    int itemType() const override;

    //getters
    int get_type() const;
    double get_buff() const;
};


#endif //OOP_ACCESSORY_H
