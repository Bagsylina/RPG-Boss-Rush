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
    explicit Accessory(const std::string& aname = "Basic Ring", const int atype_buff = 0, const double abuff_percentage = 0): Item(aname), type_buff(atype_buff), buff_percentage(abuff_percentage){
        if(type_buff < 0 || type_buff >= (int)(Types.size()))
            throw InvalidType();
        if(buff_percentage < 0 || buff_percentage > 1)
            throw InvalidData();
    }
    [[nodiscard]]Item* clone() const override {return new Accessory(*this);}

    //citire si afisare
    friend std::istream& operator>>(std::istream&, Accessory&);

    //getters
    [[nodiscard]]int get_type() const;
    [[nodiscard]]double get_buff() const;

    void useThis(Player&) override;

private:
    void print(std::ostream&) const override;
};


#endif //OOP_ACCESSORY_H
