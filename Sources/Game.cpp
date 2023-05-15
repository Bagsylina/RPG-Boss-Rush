#include "../Headers/Game.h"

void Game::addBattle(Entity &enemy, int macca_gained, int xp_gained){Battle b(player, enemy, macca_gained, xp_gained); battle_list.push_back(b);}
void Game::addShop(ShopItem s){Shop.push_back(s);}

void Game::buyShop(){
    int action = 0;
    std::cout << "Do you want to buy items?\n1: Yes  2: No\n";
    std::cin >> action;
    try {
        if(action != 1 && action != 2){
            throw InvalidInput();
        }
    }
    catch(InvalidInput& e){
        action = 2;
        std::cout << e.what();
        std::cin.clear();
        std::cin.ignore(256, '\n');
    }
    while(action == 1)
    {
        int n = Shop.size();
        std::cout << "0: Go back" << '\n';
        for(int i = 0; i < n; i++)
            if(Shop[i].get_min_level() <= player.get_level())
                std::cout << i + 1 <<": " << *Shop[i].get_product() << '\n' << "Cost: " << Shop[i].get_cost() << " Required level: " << Shop[i].get_min_level() << '\n';
        std::cin >> action;
        try {
            if(action < 1 || action > n)
                throw InvalidInput();
            if (player.get_macca() < Shop[action - 1].get_cost())
                throw NoMoney();
            if (player.get_level() < Shop[action - 1].get_min_level())
                throw NoLevel();
            player.spend_macca(Shop[action - 1].get_cost());
            player.newItem(*Shop[action - 1].get_product());
        }
        catch(InvalidInput& e){
            std::cout << e.what();
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }
        catch(NoMoney& e){
            std::cout << e.what();
        }
        catch(NoLevel& e){
            std::cout << e.what();
        }
        std::cout << "Do you want to buy items?\n1: Yes  2: No\n";
        std::cin >> action;
        try {
            if(action != 1 && action != 2){
                throw InvalidInput();
            }
        }
        catch(InvalidInput& e){
            action = 2;
            std::cout << e.what();
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }
    }
}

void Game::useItems(){
    int action = 0;
    std::cout << "Do you want to use an item?\n1: Yes 2: No\n";
    std::cin >> action;
    try {
        if(action != 1 && action != 2){
            throw InvalidInput();
        }
    }
    catch(InvalidInput& e){
        action = 2;
        std::cout << e.what();
        std::cin.clear();
        std::cin.ignore(256, '\n');
    }
    while(action == 1)
    {
        std::cout << "0: Go back" << '\n';
        player.printItems(std::cout);
        try {
            std::cin >> action;
            if(action < 1 || action > player.get_nr_items())
                throw InvalidInput();
            else
                player.useItem(action - 1);
        }
        catch(InvalidInput& e){
            std::cout << e.what();
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }
        std::cout << "Do you want to use an item?\n1: Yes 2: No\n";
        std::cin >> action;
        try {
            if(action != 1 && action != 2){
                throw InvalidInput();
            }
        }
        catch(InvalidInput& e){
            action = 2;
            std::cout << e.what();
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }
    }
}

void Game::playGame(){
    int n = battle_list.size();
    for(int i = 0; i < n && player.get_curHP() > 0; i++)
    {
        buyShop();
        useItems();
        battle_list[i].battle();
    }
}
