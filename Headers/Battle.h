#ifndef OOP_BATTLE_H
#define OOP_BATTLE_H
#include <iostream>
#include "Player.h"

class Battle{
    Player& player;
    Entity& enemy;
    bool playerGuard = false, enemyGuard = false;
    int macca_gained, xp_gained;

public:
    Battle(Player& bplayer, Entity& benemy, int bmacca_gained = 0, int bxp_gained = 0): player(bplayer), enemy(benemy), macca_gained(bmacca_gained), xp_gained(bxp_gained) {}

    bool playerAction(int);
    bool playerActionAttack();
    void playerActionItem();

    void battleTurnPlayer();
    void battleTurnEnemy();
    void battle();
};


#endif //OOP_BATTLE_H