//
// Created by Anghel Fabian on 19/04/2023.
//

#include "../Headers/Battle.h"

bool Battle::playerAction(int action){ //player action
    bool extraTurn = false;
    if(action == 1) //attack the enemy
    {
        try{
            cout << "Choose attack\n"; //printing the available skills
            int nr = player.get_nr_skills();
            if(nr == 0)
                throw NoSkills();
            Skill s;
            for(int i=0;i<nr;i++) {
                s = player.get_skill(i);
                cout << i+1 << ": " << s.get_name() << '\n';
            }
            cin >> action; //choosing the skill
                if(action > nr || action < 1)
                    throw InvalidInput();
                s = player.get_skill(action - 1);
                if (player.get_curMP() >= s.get_MP_cost()) //using the skill if there is enough MP
                    extraTurn = player.UseSkill(s, enemy, enemyGuard);
        }
        catch(NoSkills& e){
            cout << e.what();
        }
        catch(InvalidInput& e) {
            cout << e.what();
            cin.clear();
            cin.ignore(256, '\n');
        }
    }
    else if(action == 2) //guarding
    {
        playerGuard = true;
        player.guardHeal();
    }
    else if(action == 3) { //using an item
        try {
            cout << "Choose item\n"; //printing available items
            int nr = player.get_nr_items();
            if (nr == 0)
                throw NoItems();
            else {
                for (int i = 0; i < nr; i++) {
                    cout << i + 1 << ": " << player.getItem(i).get_name() << '\n';
                }
                cin >> action; //choosing an item
                if(action < 1 || action > nr)
                    throw InvalidInput();
                player.useItem(action - 1);
            }
        }
        catch(NoItems& e){
            cout << e.what();
        }
        catch(InvalidInput& e) {
            cout << e.what();
            cin.clear();
            cin.ignore(256, '\n');
        }
    }
    else // showing the full stats of the player and enemy and getting an extra turn
    {
        cout << player << '\n' << enemy << '\n';
        extraTurn = true;
    }
    return extraTurn; //returns if the player got an extra turn after his action
}
void Battle::battleTurnPlayer(){ //player turn
    playerGuard = false;
    cout << "Choose action\n" << "1: Attack\n" << "2: Guard\n" << "3: Item\n" << "4: Stats\n";
    int action = 0;
    bool extraTurn = false;
    try {
        cin >> action; //choosing an action
        if(action < 1 || action > 4)
            throw InvalidInput();
        extraTurn = playerAction(action);
    }
    catch(InvalidInput& e){
        cout << e.what();
    }
    if(extraTurn && enemy.get_curHP()) //another action if the player got an extra turn
    {
        player.afisBasicStats();
        enemy.afisBasicStats();
        cout << "Choose action\n" << "1: Attack\n" << "2: Guard\n" << "3: Item\n" << "4: Stats\n";
        try {
            cin >> action;
            if(action < 1 || action > 4)
                throw InvalidInput();
            playerAction(action);
        }
        catch(InvalidInput& e){
            cout << e.what();
            cin.clear();
            cin.ignore(256, '\n');
        }
    }
}

void Battle::battleTurnEnemy(){ //enemy turn
    enemyGuard = false;
    srand(time(0));
    int r = rand() % 5; //random chance for fighting or guarding
    if(r == 4) {
        cout << "Enemy guards.\n";
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
            player.afisBasicStats();
            enemy.afisBasicStats();
            srand(time(0));
            r = rand() % 5; //random chance for fighting or guarding
            if(r == 4) {
                cout << "Enemy guards.\n";
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
        player.afisBasicStats(); //show stats
        enemy.afisBasicStats();
        battleTurnPlayer(); //player turn
        player.afisBasicStats(); //show stats
        enemy.afisBasicStats();
        if(enemy.get_curHP()) //enemy turn
            battleTurnEnemy();
    }
    if(player.get_curHP())
        player.battle_rewards(macca_gained, xp_gained);
}