#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include <string>
#include <vector>
#include <iostream>
#include "Entity.h"
#include "Accessory.h"
#include "Armour.h"
#include "Consumable.h"
#include "ArmourUpgrade.h"
#include "Exceptions.h"

class Player : public Entity{
    int macca, xp;
    Accessory accessory;
    Armour armour;
    std::vector <Item *> inventory;

public:
    explicit Player(const std::string& pname = "Player", const int plevel = 1, const int pHP = 130, const int pMP = 50, const int pstrength = 3, const int pdexterity = 3, const int pvitality = 3, const int pagility = 3, const int pluck = 3): Entity(pname, plevel, pHP, pMP, pstrength, pdexterity, pvitality, pagility, pluck)
    {
        current_HP = HP;
        current_MP = MP;
        for(int i = 0; i <= 7; i++)
            weakness_chart[i] = 0;
        xp = 0;
        macca = 0;
    }

    Player(const Player& other): Entity(other.name, other.level, other.HP, other.MP, other.strength, other.dexterity, other.vitality, other.agility, other.luck){
        current_HP = other.current_HP;
        current_MP = other.current_MP;
        for(int i = 0; i <= 7; i++)
            weakness_chart[i] = 0;
        xp = other.xp;
        macca = other.macca;
        for(auto& i: other.inventory)
            newItem(*i);
    }

    ~Player(){
        for(auto& i: inventory)
            delete i;
        while(!inventory.empty())
            inventory.pop_back();
    }

    Player& operator = (const Player&);

    friend std::ostream& operator<<(std::ostream&, const Player&);
    void printItems(std::ostream&) const;

    //getters
    [[nodiscard]]int get_macca() const;
    [[nodiscard]]int get_nr_items() const;
    [[nodiscard]]Accessory getAccessory() const;
    [[nodiscard]]Armour getArmour() const;

    void spend_macca(int x);

    void newItem(const Item&);
    void deleteItem(int i);

    void equip_armour(const Armour&);
    void equip_accessory(const Accessory&); //equip accessory

    void battle_rewards(int, int);

    bool UseSkill(const Skill&, Entity&, bool) override;

    void useItem(int);

    void LevelUp();
};

#endif //OOP_PLAYER_H
