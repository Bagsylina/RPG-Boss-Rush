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
    Battle(Player& _player, Entity& _enemy, int _macca_gained = 0, int _xp_gained = 0): player(_player), enemy(_enemy), macca_gained(_macca_gained), xp_gained(_xp_gained) {}

    bool playerAction(int);
    bool playerActionAttack();
    void playerActionItem();

    void battleTurnPlayer();
    void battleTurnEnemy();
    void battle();
};


#endif //OOP_BATTLE_H
