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
    Skill(const std::string& sname = "", const int stype = 0, const int sbase_damage = 0, const int sMP_cost = 0, const double shit_rate = 1, const double scritical_rate = 0.01): Item(sname), type(stype), base_damage(sbase_damage), MP_cost(sMP_cost), hit_rate(shit_rate), critical_rate(scritical_rate){}
    Item* clone() const override {return new Skill(*this);}

    //constructor de copiere
    Skill(const Skill & other): Item(other.name), type(other.type), base_damage(other.base_damage), MP_cost(other.MP_cost), hit_rate(other.hit_rate), critical_rate(other.critical_rate){}

    //destructor
    virtual ~Skill() {}

    //citire si afisare
    friend std::istream& operator>>(std::istream&, Skill&);

    //operator de copiere
    Skill& operator = (const Skill&);

    //geterts
    int get_type() const;
    int get_damage() const;
    int get_MP_cost() const;
    double get_hit_rate() const;
    double get_critical_rate() const;

    void useThis(Player&) override;

private:
    void print(std::ostream&) const override;
};


#endif //OOP_SKILL_H
