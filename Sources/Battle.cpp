#include "../Headers/Battle.h"

bool Battle::playerAction(int action){ //player action
    bool extraTurn = false;
    switch(action){
        case 1: extraTurn = playerActionAttack(); break; //attack the enemy
        case 2: playerGuard = true; player.guardHeal(); break; //guarding
        case 3: playerActionItem(); break; //using an item
        case 4: std::cout << player << '\n' << enemy << '\n'; extraTurn = true; break; //showing the full stats of the player and enemy and getting an extra turn
        default: break;
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
        else
            throw NoMP();
    }
    catch(NoSkills& e){
        Skill s;
        player.learnSkill(s);
        player.UseSkill(s, enemy, enemyGuard);
        std::cout << e.what() << "Used Basic Attack.\n";
    }
    catch(NoMP& e){
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
            throw NoItems("inventory");
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
    std::cin >> action; //choosing an action
    if(action < 1 || action > 4)
    {
        std::cout<<"Invalid input\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
    }
    else
        extraTurn = playerAction(action);
    if(extraTurn && enemy.get_curHP()) //another action if the player got an extra turn
    {
        std::cout << "You get another turn!\n";
        player.afisBasicStats(std::cout);
        enemy.afisBasicStats(std::cout);
        std::cout << "Choose action\n" << "1: Attack\n" << "2: Guard\n" << "3: Item\n" << "4: Stats\n";
        std::cin >> action; //choosing an action
        if(action < 1 || action > 4)
        {
            std::cout<<"Invalid input\n";
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }
        else
            playerAction(action);
    }
}

bool Battle::enemyActionAttack(){
    bool extraTurn = false;
    int nr = enemy.get_nr_skills();
    try {
        if(nr == 0)
            throw NoSkills();
        int r = rand() % nr; //use random skill
        Skill s = enemy.get_skill(r);
        if(enemy.get_curMP() < s.get_MP_cost())
            throw NoMP();
        extraTurn = enemy.UseSkill(s, player, playerGuard);
    }
    catch(NoSkills&){
        Skill s;
        enemy.learnSkill(s);
        extraTurn = enemy.UseSkill(s, player, playerGuard);
    }
    catch(NoMP&){
        enemyActionGuard();
    }
    return extraTurn;
}

void Battle::enemyActionGuard(){
    std::cout << "Enemy guards.\n";
    enemyGuard = true;
    enemy.guardHeal();
}

void Battle::battleTurnEnemy(){ //enemy turn
    enemyGuard = false;
    int r = rand() % 5; //random chance for fighting or guarding
    if(r == 4)
        enemyActionGuard();
    else
    {
        bool extraTurn = enemyActionAttack();
        if(extraTurn) //another action if the enemy got an extra turn
        {
            std::cout << "Enemy gets another turn!\n";
            player.afisBasicStats(std::cout);
            enemy.afisBasicStats(std::cout);
            r = rand() % 5; //random chance for fighting or guarding
            if(r == 4)
                enemyActionGuard();
            else
                enemyActionAttack();
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