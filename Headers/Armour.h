#ifndef OOP_ARMOUR_H
#define OOP_ARMOUR_H
#include <string>
#include "Item.h"
#include <iostream>

class Armour : public Item{
    int bonus_HP, bonus_MP, bonus_strength, bonus_dexterity, bonus_vitality, bonus_agility, bonus_luck;
public:
    //constructor
    explicit Armour(const std::string& aname = "Basic Armour", int abonus_HP = 0, int abonus_MP = 0, int abonus_strength = 0, int abonus_dexterity = 0, int abonus_vitality = 0, int abonus_agility = 0, int abonus_luck = 0);
    [[nodiscard]]Item* clone() const override;

    //citire si afisare
    friend std::istream& operator>>(std::istream& in, Armour& a);

    //getters
    [[nodiscard]]int get_bHP() const;
    [[nodiscard]]int get_bMP() const;
    [[nodiscard]]int get_bstr() const;
    [[nodiscard]]int get_bdex() const;
    [[nodiscard]]int get_bvit() const;
    [[nodiscard]]int get_bagi() const;
    [[nodiscard]]int get_blck() const;

    void useThis(Player&) override;

private:
    void print(std::ostream&) const override;
};


#endif //OOP_ARMOUR_H
