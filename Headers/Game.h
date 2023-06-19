#ifndef OOP_GAME_H
#define OOP_GAME_H
#include <iostream>
#include <vector>
#include "ShopItem.h"
#include "Battle.h"

class Game{
    Player player;
    std::vector <Battle> battle_list;
    std::vector <ShopItem<Item>> Shop;

public:
    explicit Game();

    void addBattle(Entity&, int, int);
    void addShop(const ShopItem<Item>&);

    void buyShop();
    void useItems();

    void playGame();

    Player& get_player();
};


#endif //OOP_GAME_H
