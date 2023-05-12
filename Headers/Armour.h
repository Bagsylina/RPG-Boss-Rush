#ifndef OOP_ARMOUR_H
#define OOP_ARMOUR_H
#include <string>
#include "Item.h"
#include <iostream>

class Armour : public Item{
    int bonus_HP, bonus_MP, bonus_strength, bonus_dexterity, bonus_vitality, bonus_agility, bonus_luck;
public:
    //constructor
    Armour(const std::string& _name = "Basic Armour", const int _bonus_HP = 0, const int _bonus_MP = 0, const int _bonus_strength = 0, const int _bonus_dexterity = 0, const int _bonus_vitality = 0, const int _bonus_agility = 0, const int _bonus_luck = 0): Item(_name), bonus_HP(_bonus_HP), bonus_MP(_bonus_MP), bonus_strength(_bonus_strength), bonus_dexterity(_bonus_dexterity), bonus_vitality(_bonus_vitality), bonus_agility(_bonus_agility), bonus_luck(_bonus_luck) {}
    Item* clone() const override {return new Armour(*this);}

    //citire si afisare
    friend std::istream& operator>>(std::istream& in, Armour& a)
    {
        in >> a.name >> a.bonus_HP >> a.bonus_MP >> a.bonus_strength >> a.bonus_dexterity >> a.bonus_vitality >> a.bonus_agility >> a.bonus_luck;
        return in;
    }

    friend std::ostream& operator<<(std::ostream&, const Armour&);

    void print(std::ostream&) const override;

    int itemType()const override;

    //getters
    int get_bHP() const;
    int get_bMP() const;
    int get_bstr() const;
    int get_bdex() const;
    int get_bvit() const;
    int get_bagi() const;
    int get_blck() const;

};


#endif //OOP_ARMOUR_H
