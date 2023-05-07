//
// Created by Anghel Fabian on 19/04/2023.
//

#ifndef OOP_GAME_H
#define OOP_GAME_H
#include <iostream>
#include <vector>
#include "Player.h"
#include "ShopItem.h"
#include "Battle.h"

class Game{
    Player& player;
    vector <Battle> battle_list;
    vector <ShopItem> Shop;

public:
    explicit Game(Player& _player): player(_player) {}

    void addBattle(Entity&, int, int);
    void addShop(ShopItem);

    void buyShop();
    void useItems();

    void playGame();
};


#endif //OOP_GAME_H
