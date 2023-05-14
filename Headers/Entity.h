#ifndef OOP_ENTITY_H
#define OOP_ENTITY_H
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"
#include "Skill.h"

class Entity {
protected:
    std::string name;
    std::vector <Skill> skill_list;
    int level, HP, MP, strength, dexterity, vitality, agility, luck;
    int current_HP, current_MP;
    int weakness_chart[8];
    static const std::vector <std::string> Types;

public:
    Entity(const std::string& ename = "Demon", const int elevel = 1, const int eHP = 100, const int eMP = 30, const int estrength = 3, const int edexterity = 3, const int evitality = 3, const int eagility = 3, const int eluck = 3): name(ename), level(elevel), HP(eHP), MP(eMP), strength(estrength), dexterity(edexterity), vitality(evitality), agility(eagility), luck(eluck)
    {
        current_HP = HP;
        current_MP = MP;
        for(int i = 0; i <= 7; i++)
            weakness_chart[i] = 0;
    }

    friend std::istream& operator>>(std::istream&, Entity&);
    friend std::ostream& operator<<(std::ostream&, const Entity&);
    void afisBasicStats(std::ostream&) const;
    void printSkills(std::ostream&) const;

    int get_level() const;
    int get_curHP() const;
    int get_curMP() const;
    int get_vit() const;
    int get_agi() const;
    int get_lck() const;
    int get_weakness(const int) const;
    int get_nr_skills() const;
    Skill get_skill(const int) const;

    void changeWeakness(const int, const int);

    void takedamage(const int);

    void learnSkill(const Skill&);
    void forgetSkill(const int);
    virtual bool UseSkill(const Skill&, Entity&, const bool);

    void guardHeal();
    void heal(int, int);
};


#endif //OOP_ENTITY_H
