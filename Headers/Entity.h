#ifndef OOP_ENTITY_H
#define OOP_ENTITY_H
#include <string>
#include <vector>
#include <iostream>
#include <random>
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
    explicit Entity(std::string ename = "Demon", const int elevel = 1, const int eHP = 100, const int eMP = 30, const int estrength = 3, const int edexterity = 3, const int evitality = 3, const int eagility = 3, const int eluck = 3): name{std::move(ename)}, level(elevel), HP(eHP), MP(eMP), strength(estrength), dexterity(edexterity), vitality(evitality), agility(eagility), luck(eluck)
    {
        if(HP <= 0 || MP <= 0 || strength <= 0 || dexterity <= 0 || vitality <= 0 || agility <= 0 || luck <= 0)
            throw InvalidData();
        current_HP = HP;
        current_MP = MP;
        for(int i = 0; i <= 7; i++)
            weakness_chart[i] = 0;
    }

    friend std::istream& operator>>(std::istream&, Entity&);
    friend std::ostream& operator<<(std::ostream&, const Entity&);
    void afisBasicStats(std::ostream&) const;
    void printSkills(std::ostream&) const;

    [[nodiscard]]int get_level() const;
    [[nodiscard]]int get_curHP() const;
    [[nodiscard]]int get_curMP() const;
    [[nodiscard]]int get_vit() const;
    [[nodiscard]]int get_agi() const;
    [[nodiscard]]int get_lck() const;
    [[nodiscard]]int get_weakness(int) const;
    [[nodiscard]]int get_nr_skills() const;
    [[nodiscard]]Skill get_skill(int) const;

    void changeWeakness(int, int);

    void takedamage(int);

    void learnSkill(const Skill&);
    void forgetSkill(int);
    virtual bool UseSkill(const Skill&, Entity&, bool);

    void guardHeal();
    void heal(int, int);
};


#endif //OOP_ENTITY_H
