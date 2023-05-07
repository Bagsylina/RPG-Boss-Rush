//
// Created by Anghel Fabian on 19/04/2023.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include <string>
#include <vector>
#include <iostream>
#include "Entity.h"
#include "Accessory.h"
#include "Armour.h"
#include "Consumable.h"

using namespace std;

class Player : public Entity{
    int macca, xp;
    Accessory accessory;
    Armour armour;
    vector <Item *> inventory;

public:
    Player(const string& name_ = "Player", const int _level = 1, const int HP_ = 130, const int MP_ = 50, const int _strength = 3, const int _dexterity = 3, const int _vitality = 3, const int _agility = 3, const int _luck = 3): Entity(name_, _level, HP_, MP_, _strength, _dexterity, _vitality, _agility, _luck)
    {
        current_HP = HP;
        current_MP = MP;
        for(int i = 0; i <= 7; i++)
            weakness_chart[i] = 0;
        xp = 0;
        macca = 0;
    }

    friend ostream& operator<<(ostream& out, const Player& e)
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
        out << "Armour: " << e.armour << '\n';
        out << "Accessory: " << e.accessory << '\n';
        out << "Number of items in inventory: " << e.inventory.size() << '\n';
        for(int i = 0; i < e.inventory.size(); i++)
            out << *e.inventory[i] << '\n';
        return out;
    }

    //getters
    int get_macca() const;
    int get_nr_items() const;
    Item getItem(const int) const;
    Accessory getAccessory() const;
    Armour getArmour() const;

    //virtual void printSkills();

    virtual void forgetSkill(const int);

    void spend_macca(int x);

    void newItem(Item*);

    void deleteItem(int i);

    void equip_armour(const Armour&);

    void equip_accessory(const Accessory&); //equip accessory

    void battle_rewards(const int, const int);

    bool UseSkill(const Skill&, Entity&, const bool guard);

    void useItem(int);

    void printItems();
};

#endif //OOP_PLAYER_H
