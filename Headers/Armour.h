#ifndef OOP_ARMOUR_H
#define OOP_ARMOUR_H
#include <string>
#include "Item.h"
#include <iostream>

class Armour : public Item{
    int bonus_HP, bonus_MP, bonus_strength, bonus_dexterity, bonus_vitality, bonus_agility, bonus_luck;
public:
    //constructor
    Armour(const std::string& aname = "Basic Armour", const int abonus_HP = 0, const int abonus_MP = 0, const int abonus_strength = 0, const int abonus_dexterity = 0, const int abonus_vitality = 0, const int abonus_agility = 0, const int abonus_luck = 0): Item(aname), bonus_HP(abonus_HP), bonus_MP(abonus_MP), bonus_strength(abonus_strength), bonus_dexterity(abonus_dexterity), bonus_vitality(abonus_vitality), bonus_agility(abonus_agility), bonus_luck(abonus_luck) {}
    Item* clone() const override {return new Armour(*this);}

    //citire si afisare
    friend std::istream& operator>>(std::istream& in, Armour& a)
    {
        in >> a.name >> a.bonus_HP >> a.bonus_MP >> a.bonus_strength >> a.bonus_dexterity >> a.bonus_vitality >> a.bonus_agility >> a.bonus_luck;
        return in;
    }

    //getters
    int get_bHP() const;
    int get_bMP() const;
    int get_bstr() const;
    int get_bdex() const;
    int get_bvit() const;
    int get_bagi() const;
    int get_blck() const;

    void useThis(Player&) override;

private:
    void print(std::ostream&) const override;
};


#endif //OOP_ARMOUR_H
