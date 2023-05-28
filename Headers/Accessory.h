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
    explicit Accessory(const std::string& aname = "Basic Ring", int atype_buff = 0, double abuff_percentage = 0);
    [[nodiscard]]Item* clone() const override;

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
