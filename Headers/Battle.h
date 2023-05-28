#ifndef OOP_BATTLE_H
#define OOP_BATTLE_H
#include <iostream>
#include <random>
#include "Player.h"

class Battle{
    Player& player;
    Entity& enemy;
    bool playerGuard = false, enemyGuard = false;
    int macca_gained, xp_gained;

public:
    Battle(Player& bplayer, Entity& benemy, int bmacca_gained = 0, int bxp_gained = 0);

    bool playerAction(int);
    bool playerActionAttack();
    void playerActionItem();

    bool enemyActionAttack();
    void enemyActionGuard();

    void battleTurnPlayer();
    void battleTurnEnemy();
    void battle();
};


#endif //OOP_BATTLE_H
