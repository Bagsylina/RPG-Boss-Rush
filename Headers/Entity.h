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
    Entity(const std::string& name_ = "Demon", const int _level = 1, const int HP_ = 100, const int MP_ = 30, const int _strength = 3, const int _dexterity = 3, const int _vitality = 3, const int _agility = 3, const int _luck = 3): name(name_), level(_level), HP(HP_), MP(MP_), strength(_strength), dexterity(_dexterity), vitality(_vitality), agility(_agility), luck(_luck)
    {
        current_HP = HP;
        current_MP = MP;
        for(int i = 0; i <= 7; i++)
            weakness_chart[i] = 0;
    }

    friend std::istream& operator>>(std::istream&, Entity&);
    friend std::ostream& operator<<(std::ostream&, const Entity&);
    void afisBasicStats(std::ostream&) const;
    void printSkills() const;

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
