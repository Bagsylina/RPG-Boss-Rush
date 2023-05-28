#ifndef OOP_CONSUMABLE_H
#define OOP_CONSUMABLE_H
#include <string>
#include <iostream>
#include "Item.h"

class Consumable : public Item{
    int HP_heal, MP_heal;
public:
    //constructor
    explicit Consumable(const std::string& cname = "Food", int cHP_heal = 0, int cMP_heal = 0);
    [[nodiscard]]Item* clone() const override;

    //citire si afisare
    friend std::istream& operator>>(std::istream&, Consumable&);

    //getters
    [[nodiscard]]int get_HP_heal() const;
    [[nodiscard]]int get_MP_heal() const;

    void useThis(Player&) override;

private:
    void print(std::ostream&) const override;
};


#endif //OOP_CONSUMABLE_H
