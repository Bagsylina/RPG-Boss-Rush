#include "Headers/Game.h"

int main() {
    srand(time(nullptr));
    try {
        Game g;
        Entity pixie("Pixie", 3, 100, 100, 4, 7, 3, 6, 4);
        Entity drunk("Drunk", 4, 210, 50, 7, 1, 2, 1, 7);
        Skill punch("Punch", 0, 10, 0, 1, 0.2), knife("Knife", 1, 25, 10, 1, 0.2);
        Skill gun("Gun", 2, 40, 30, 0.8, 0.1), taser("Taser", 5, 30, 20, 0.95, 0.05);
        Skill agi("Agi", 3, 20, 8, 1, 0.05), zan("Zan", 7, 20, 8, 1, 0.05);
        Accessory battery("Battery", 5, 0.2);
        Armour_Builder ab;
        Armour shirt = ab.name("Tshirt").bonus_HP(10).bonus_MP(5).bonus_dexterity(1).bonus_agility(1).build();
        Consumable burger("Burger", 100, 10), energy("Energy drink", 0, 120), pizza("Pizza", 300, 50), bandage(
                "Bandage", 60, 0);
        ArmourUpgrade undershirt("Undershirt", 1, 1, 1);
        g.get_player().equip_accessory(battery);
        g.get_player().equip_armour(shirt);
        g.get_player().newItem(burger);
        g.get_player().newItem(pizza);
        g.get_player().newItem(energy);
        g.get_player().newItem(energy);
        g.get_player().newItem(bandage);
        g.get_player().newItem(bandage);
        g.get_player().newItem(bandage);
        g.get_player().newItem(undershirt);
        g.get_player().learnSkill(punch);
        g.get_player().learnSkill(knife);
        g.get_player().learnSkill(gun);
        g.get_player().learnSkill(taser);
        pixie.learnSkill(agi);
        pixie.learnSkill(zan);
        drunk.learnSkill(punch);
        drunk.learnSkill(knife);
        pixie.changeWeakness(2, -1);
        pixie.changeWeakness(5, -1);
        pixie.changeWeakness(0, 2);
        drunk.changeWeakness(0, 1);
        drunk.changeWeakness(1, -1);
        drunk.changeWeakness(5, 3);
        Entity::printTypes(std::cout);
        g.addBattle(pixie, 100, 1000);
        g.addBattle(drunk, 10, 570);
        Skill sharp_knife("Sharp Knife", 1, 60, 8, 0.98, 0.4);
        Skill *sk = &sharp_knife;
        Item *p1 = &sharp_knife, *p2 = &bandage, *p3 = &battery, *p4 = &shirt;
        ShopItem<Item> s1(p1, 30, 4), s2(p2, 10, 1), s3(p3, 0, 1), s4(p4, 0, 1);
        g.addShop(s1);
        g.addShop(s2);
        g.addShop(s3);
        g.addShop(s4);
        ShopItem<Skill> s5(sk, 0, 5);
        g.addReward(s5);
        g.playGame();
        drunk.forgetSkill(0);
        Item* dc = burger.clone();
        Consumable* dc1 = dynamic_cast<Consumable*>(dc);
        if(dc1 == NULL)
            std::cout << "Dynamic cast failed!";
        else
            std::cout << "Dynamic cast was successful.";
        delete dc;
    }
    catch(GameError& e)
    {
        std::cout << e.what();
    }
    return 0;
}
