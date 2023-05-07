//
// Created by Anghel Fabian on 19/04/2023.
//

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
    //citire si afisare
    friend std::istream& operator>>(std::istream& in, Armour& a)
    {
        in >> a.name >> a.bonus_HP >> a.bonus_MP >> a.bonus_strength >> a.bonus_dexterity >> a.bonus_vitality >> a.bonus_agility >> a.bonus_luck;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Armour& ar)
    {
        out << ar.name;
        if(ar.bonus_HP)
            out << '\n' << "Bonus HP: " << ar.bonus_HP;
        if(ar.bonus_MP)
            out << '\n' << "Bonus MP: " << ar.bonus_MP;
        if(ar.bonus_strength)
            out << '\n' << "Bonus Strength: " << ar.bonus_strength;
        if(ar.bonus_dexterity)
            out << '\n' << "Bonus Dexterity : " << ar.bonus_dexterity;
        if(ar.bonus_vitality)
            out << '\n' << "Bonus Vitality: " << ar.bonus_vitality;
        if(ar.bonus_agility)
            out << '\n' << "Bonus Agility: " << ar.bonus_agility;
        if(ar.bonus_luck)
            out << '\n' << "Bonus Luck: " << ar.bonus_luck;
        return out;
    }

    int itemType(){return 3;}

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
