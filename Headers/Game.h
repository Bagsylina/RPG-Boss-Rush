#ifndef OOP_GAME_H
#define OOP_GAME_H
#include <iostream>
#include <vector>
#include "ShopItem.h"
#include "Battle.h"

class Game{
    Player& player;
    std::vector <Battle> battle_list;
    std::vector <ShopItem> Shop;

public:
    explicit Game(Player& gplayer): player(gplayer) {}

    void addBattle(Entity&, int, int);
    void addShop(const ShopItem&);

    void buyShop();
    void useItems();

    void playGame();
};


#endif //OOP_GAME_H
