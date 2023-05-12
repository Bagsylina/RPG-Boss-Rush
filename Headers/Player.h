#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include <string>
#include <vector>
#include <iostream>
#include "Entity.h"
#include "Accessory.h"
#include "Armour.h"
#include "Consumable.h"
#include "Exceptions.h"

class Player : public Entity{
    int macca, xp;
    Accessory accessory;
    Armour armour;
    std::vector <Item *> inventory;

public:
    Player(const std::string& name_ = "Player", const int _level = 1, const int HP_ = 130, const int MP_ = 50, const int _strength = 3, const int _dexterity = 3, const int _vitality = 3, const int _agility = 3, const int _luck = 3): Entity(name_, _level, HP_, MP_, _strength, _dexterity, _vitality, _agility, _luck)
    {
        current_HP = HP;
        current_MP = MP;
        for(int i = 0; i <= 7; i++)
            weakness_chart[i] = 0;
        xp = 0;
        macca = 0;
    }
    ~Player(){
        for(auto& i: inventory)
            delete i;
    }

    friend std::ostream& operator<<(std::ostream&, const Player&);
    void printItems() const;

    //getters
    int get_macca() const;
    int get_nr_items() const;
    Accessory getAccessory() const;
    Armour getArmour() const;

    void spend_macca(int x);

    void newItem(Item*);
    void deleteItem(int i);

    void equip_armour(const Armour&);
    void equip_accessory(const Accessory&); //equip accessory

    void battle_rewards(const int, const int);

    bool UseSkill(const Skill&, Entity&, const bool guard) override;

    void useItem(int);
    void useItemSkill(Item*);
    void useItemAccessory(Item*);
    void useItemArmour(Item*);

    void LevelUp();
};

#endif //OOP_PLAYER_H
