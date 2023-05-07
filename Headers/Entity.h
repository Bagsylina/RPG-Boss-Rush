//
// Created by Anghel Fabian on 19/04/2023.
//

#ifndef OOP_ENTITY_H
#define OOP_ENTITY_H
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"
#include "Skill.h"

using namespace std;

class Entity {
protected:
    string name;
    vector <Skill> skill_list;
    int level, HP, MP, strength, dexterity, vitality, agility, luck;
    int current_HP, current_MP;
    int weakness_chart[8];

public:
    Entity(const string& name_ = "Demon", const int _level = 1, const int HP_ = 100, const int MP_ = 30, const int _strength = 3, const int _dexterity = 3, const int _vitality = 3, const int _agility = 3, const int _luck = 3): name(name_), level(_level), HP(HP_), MP(MP_), strength(_strength), dexterity(_dexterity), vitality(_vitality), agility(_agility), luck(_luck)
    {
        current_HP = HP;
        current_MP = MP;
        for(int i = 0; i <= 7; i++)
            weakness_chart[i] = 0;
    }

    friend istream& operator>>(istream& in, Entity& e)
    {
        in >> e.name >> e.level >> e.HP >> e.MP >> e.strength >> e.dexterity >> e.vitality >> e.agility >> e.luck;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Entity& e)
    {
        out << e.name << '\n' << "Level " << e.level << '\n';
        out << "HP: " << e.current_HP << '/' << e.HP << " MP: "<< e.current_MP << '/' << e.MP << '\n';
        out << "Strength: " << e.strength << " Dexterity: " << e.dexterity << " Vitality: " << e.vitality << " Agility: "<< e.agility << " Luck: " << e.luck << '\n';
        out << "Number of skills: " << e.skill_list.size() << '\n';
        int nr=e.skill_list.size();
        for(int i = 0; i < nr; i++)
            out << e.skill_list[i] << '\n';
        for(int i = 0; i < 8; i++)
        {
            switch (e.weakness_chart[i]) {
                case -1: out << "Weak to "; break;
                case 0: out << "Normal damage from "; break;
                case 1: out << "Resistant to "; break;
                case 2: out << "No damage from "; break;
                case 3: out << "Reflects "; break;
                case 4: out << "Absorbs "; break;
            }
            out << Types[i] << '\n';
        }
        return out;
    }

    void afisBasicStats();

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

    virtual void printSkills();

    virtual void forgetSkill(const int);

    void guardHeal();

    void heal(int, int);

    virtual bool UseSkill(const Skill&, Entity&, const bool);
};


#endif //OOP_ENTITY_H
