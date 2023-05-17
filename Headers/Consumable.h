#ifndef OOP_CONSUMABLE_H
#define OOP_CONSUMABLE_H
#include <string>
#include <iostream>
#include "Item.h"

class Consumable : public Item{
    int HP_heal, MP_heal;
public:
    //constructor
    explicit Consumable(const std::string& cname = "Food", const int cHP_heal = 0, const int cMP_heal = 0): Item(cname), HP_heal(cHP_heal), MP_heal(cMP_heal) {
        if(HP_heal < 0 || MP_heal < 0)
            throw InvalidHeal();
    }
    [[nodiscard]]Item* clone() const override {return new Consumable(*this);}

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
