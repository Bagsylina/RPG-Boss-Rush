//
// Created by Anghel Fabian on 19/04/2023.
//

#ifndef OOP_SKILL_H
#define OOP_SKILL_H
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"

class Skill: public Item{
    int type, base_damage, MP_cost;
    double hit_rate, critical_rate;

public:

    // constructor
    Skill(const std::string& _name = "", const int _type = 0, const int _base_damage = 0, const int _MP_cost = 0, const double _hit_rate = 1, const double _critical_rate = 0.01): Item(_name), type(_type), base_damage(_base_damage), MP_cost(_MP_cost), hit_rate(_hit_rate), critical_rate(_critical_rate){}

    //constructor de copiere
    Skill(const Skill & other): Item(other.name), type(other.type), base_damage(other.base_damage), MP_cost(other.MP_cost), hit_rate(other.hit_rate), critical_rate(other.critical_rate){}

    //destructor
    virtual ~Skill() {}

    //citire si afisare
    friend std::istream& operator>>(std::istream&, Skill&);

    friend std::ostream& operator<<(std::ostream&, const Skill&);

    //operator de copiere
    Skill& operator = (const Skill& other)
    {
        name = other.name;
        type = other.type;
        base_damage = other.base_damage;
        MP_cost = other.MP_cost;
        hit_rate = other.hit_rate;
        critical_rate = other.critical_rate;
        return *this;
    }

    int itemType() override{return 1;}

    //geterts
    int get_type() const;
    int get_damage() const;
    int get_MP_cost() const;
    double get_hit_rate() const;
    double get_critical_rate() const;
};


#endif //OOP_SKILL_H
