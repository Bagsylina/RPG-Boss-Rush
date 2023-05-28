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
    explicit Entity(std::string ename = "Demon", int elevel = 1, int eHP = 100, int eMP = 30, int estrength = 3, int edexterity = 3, int evitality = 3, int eagility = 3, int eluck = 3);

    friend std::istream& operator>>(std::istream&, Entity&);
    friend std::ostream& operator<<(std::ostream&, const Entity&);
    void afisBasicStats(std::ostream&) const;
    void printSkills(std::ostream&) const;
    static void printTypes(std::ostream&);

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
