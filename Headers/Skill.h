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
    explicit Skill(const std::string& sname = "", int stype = 0, int sbase_damage = 10, int sMP_cost = 0, double shit_rate = 1, double scritical_rate = 0.01);
    [[nodiscard]]Item* clone() const override;

    //constructor de copiere
    Skill(const Skill & other);

    //citire si afisare
    friend std::istream& operator>>(std::istream&, Skill&);

    //operator de copiere
    Skill& operator = (const Skill&);

    //geterts
    [[nodiscard]]int get_type() const;
    [[nodiscard]]int get_damage() const;
    [[nodiscard]]int get_MP_cost() const;
    [[nodiscard]]double get_hit_rate() const;
    [[nodiscard]]double get_critical_rate() const;

    void useThis(Player&) override;

private:
    void print(std::ostream&) const override;
};


#endif //OOP_SKILL_H
