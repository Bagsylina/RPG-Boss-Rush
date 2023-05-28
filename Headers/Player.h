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

#endif //OOP_PLAYER_H
