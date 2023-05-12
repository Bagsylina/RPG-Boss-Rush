#include "Headers/Game.h"

int main() {
    Player player("Bagsylina", 5, 172, 121, 5, 5, 5, 5, 5);
    Entity pixie("Pixie", 3, 100, 100, 4, 7, 3, 6, 4);
    Entity drunk("Drunk", 4, 210, 50, 7, 1, 2, 1, 7);
    Skill punch("Punch", 0, 10, 0, 1, 0.2), knife("Knife", 1, 25, 10, 1, 0.2);
    Skill gun("Gun", 2, 40, 30, 0.8, 0.1), taser("Taser", 5, 30, 20, 0.95, 0.05);
    Skill agi("Agi", 3, 20, 8, 1, 0.05), zan("Zan", 7, 20, 8, 1, 0.05);
    Accessory battery("Battery", 5, 0.2);
    Armour shirt("Tshirt", 10, 5, 0, 1, 0, 1, 0);
    Consumable burger("Burger", 100, 10), energy("Energy drink", 0, 120), pizza("Pizza", 300, 50), bandage("Bandage", 60, 0);
    player.equip_accessory(battery);
    player.equip_armour(shirt);
    player.newItem(&burger);
    player.newItem(&pizza);
    player.newItem(&energy);
    player.newItem(&energy);
    player.newItem(&bandage);
    player.newItem(&bandage);
    player.newItem(&bandage);
    std::cout << player << '\n';
    player.learnSkill(punch);player.learnSkill(knife);player.learnSkill(gun);player.learnSkill(taser);
    pixie.learnSkill(agi);pixie.learnSkill(zan);
    drunk.learnSkill(punch);drunk.learnSkill(knife);
    pixie.changeWeakness(2, -1);
    pixie.changeWeakness(5, -1);
    pixie.changeWeakness(0, 2);
    drunk.changeWeakness(0, 1);
    drunk.changeWeakness(1, -1);
    drunk.changeWeakness(5, 3);
    Game g(player);
    g.addBattle(pixie, 100, 200);
    g.addBattle(drunk, 10, 570);
    Skill sharp_knife("Sharp Knife", 1, 60, 8, 0.98, 0.4);
    Item *p1 = &sharp_knife, *p2 = &bandage, *p3 = &battery, *p4 = &shirt;
    ShopItem s1(p1, 30, 4), s2(p2, 10, 1), s3(p3, 0, 1), s4(p4, 0, 1);
    g.addShop(s1);
    g.addShop(s2);
    g.addShop(s3);
    g.addShop(s4);
    g.playGame();
    drunk.forgetSkill(0);
    return 0;
}
