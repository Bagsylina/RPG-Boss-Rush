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
    explicit Player(const std::string& pname = "Player", int plevel = 1, int pHP = 130, int pMP = 50, int pstrength = 3, int pdexterity = 3, int pvitality = 3, int pagility = 3, int pluck = 3);

    Player(const Player& other);

    ~Player();

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

class Player_Factory{
public:
    static Player Warrior() {return Player("Warrior", 5, 200, 100, 7, 3, 7, 4, 4);}
    static Player Sniper() {return Player("Sniper", 5, 130, 170, 3, 7, 4, 6, 5);}
    static Player Runner() {return Player("Warrior", 5, 170, 130, 6, 6, 3, 7, 3);}
    static Player Tank() {return Player("Tank", 5, 250, 50, 4, 4, 9, 3, 5);}
    static Player Lucky() {return Player("Lucky", 5, 180, 120, 5, 5, 4, 4, 7);}
    static Player Base() {return Player("Base", 5, 175, 125, 5, 5, 5, 5, 5);}
};

#endif //OOP_PLAYER_H
