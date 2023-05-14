#include "../Headers/Battle.h"

bool Battle::playerAction(int action){ //player action
    bool extraTurn = false;
    switch(action){
        case 1: extraTurn = playerActionAttack(); break; //attack the enemy
        case 2: playerGuard = true; player.guardHeal(); break; //guarding
        case 3: playerActionItem(); break; //using an item
        case 4: std::cout << player << '\n' << enemy << '\n'; extraTurn = true; break; //showing the full stats of the player and enemy and getting an extra turn
    }
    return extraTurn; //returns true if the player got an extra turn after his action
}

bool Battle::playerActionAttack(){
    bool extraTurn = false;
    std::cout << "Choose attack\n"; //printing the available skills
    try{
        int nr = player.get_nr_skills();
        if(nr == 0)
            throw NoSkills();
        player.printSkills(std::cout);
        int action = 0;
        std::cin >> action; //choosing the skill
        if(action > nr || action < 1)
            throw InvalidInput();
        Skill s = player.get_skill(action - 1);
        if (player.get_curMP() >= s.get_MP_cost()) //using the skill if there is enough MP
            extraTurn = player.UseSkill(s, enemy, enemyGuard);
    }
    catch(NoSkills& e){
        std::cout << e.what();
    }
    catch(InvalidInput& e) {
        std::cout << e.what();
        std::cin.clear();
        std::cin.ignore(256, '\n');
    }
    return extraTurn;
}

void Battle::playerActionItem(){
    std::cout << "Choose item\n"; //printing available items
    try {
        int nr = player.get_nr_items();
        if (nr == 0)
            throw NoItems();
        player.printItems(std::cout);
        int action = 0;
        std::cin >> action; //choosing an item
        if(action < 1 || action > nr)
            throw InvalidInput();
        player.useItem(action - 1);
    }
    catch(NoItems& e){
        std::cout << e.what();
    }
    catch(InvalidInput& e) {
        std::cout << e.what();
        std::cin.clear();
        std::cin.ignore(256, '\n');
    }
}


void Battle::battleTurnPlayer(){ //player turn
    playerGuard = false;
    std::cout << "Choose action\n" << "1: Attack\n" << "2: Guard\n" << "3: Item\n" << "4: Stats\n";
    int action = 0;
    bool extraTurn = false;
    try {
        std::cin >> action; //choosing an action
        if(action < 1 || action > 4)
            throw InvalidInput();
        extraTurn = playerAction(action);
    }
    catch(InvalidInput& e){
        std::cout << e.what();
        std::cin.clear();
        std::cin.ignore(256, '\n');
    }
    if(extraTurn && enemy.get_curHP()) //another action if the player got an extra turn
    {
        std::cout << "You get another turn!\n";
        player.afisBasicStats(std::cout);
        enemy.afisBasicStats(std::cout);
        std::cout << "Choose action\n" << "1: Attack\n" << "2: Guard\n" << "3: Item\n" << "4: Stats\n";
        try {
            std::cin >> action;
            if(action < 1 || action > 4)
                throw InvalidInput();
            playerAction(action);
        }
        catch(InvalidInput& e){
            std::cout << e.what();
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }
    }
}

void Battle::battleTurnEnemy(){ //enemy turn
    enemyGuard = false;
    srand(time(0));
    int r = rand() % 5; //random chance for fighting or guarding
    if(r == 4) {
        std::cout << "Enemy guards.\n";
        enemyGuard = true;
        enemy.guardHeal();
    }
    else
    {
        srand(time(0));
        r = rand() % enemy.get_nr_skills(); //use random skill
        Skill s = enemy.get_skill(r);
        bool extraTurn = false;
        if(enemy.get_curMP() >= s.get_MP_cost())
            extraTurn = enemy.UseSkill(s, player, playerGuard);
        if(extraTurn) //another action if the enemy got an extra turn
        {
            std::cout << "Enemy gets another turn!\n";
            player.afisBasicStats(std::cout);
            enemy.afisBasicStats(std::cout);
            srand(time(0));
            r = rand() % 5; //random chance for fighting or guarding
            if(r == 4) {
                std::cout << "Enemy guards.\n";
                enemyGuard = true;
                enemy.guardHeal();
            }
            else
            {
                r = rand() % enemy.get_nr_skills(); //use random skill
                s = enemy.get_skill(r);
                if(enemy.get_curMP() >= s.get_MP_cost())
                    enemy.UseSkill(s, player, playerGuard);
            }
        }
    }
}

void Battle::battle(){
    while(player.get_curHP() && enemy.get_curHP())
    {
        player.afisBasicStats(std::cout); //show stats
        enemy.afisBasicStats(std::cout);
        battleTurnPlayer(); //player turn
        player.afisBasicStats(std::cout); //show stats
        enemy.afisBasicStats(std::cout);
        if(enemy.get_curHP()) //enemy turn
            battleTurnEnemy();
    }
    if(player.get_curHP())
        player.battle_rewards(macca_gained, xp_gained);
}