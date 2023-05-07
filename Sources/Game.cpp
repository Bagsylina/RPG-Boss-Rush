//
// Created by Anghel Fabian on 19/04/2023.
//

#include "../Headers/Game.h"

void Game::addBattle(Entity &enemy, int macca_gained, int xp_gained){Battle b(player, enemy, macca_gained, xp_gained); battle_list.push_back(b);}
void Game::addShop(ShopItem s){Shop.push_back(s);}

void Game::buyShop(){
    int action = 0;
    cout << "Do you want to buy items?\n1: Yes  2: No\n";
    cin >> action;
    while(action == 1)
    {
        int n = Shop.size();
        cout << "0: Go back" << '\n';
        for(int i = 0; i < n; i++)
            cout << i + 1 <<": " << *Shop[i].get_product() << '\n' << "Cost: " << Shop[i].get_cost() << " Required level: " << Shop[i].get_min_level() << '\n';
        cin >> action;
        if (action > 0)
        {
            if(player.get_macca() < Shop[action-1].get_cost())
                cout << "Not enough money\n";
            else if(player.get_level() < Shop[action-1].get_min_level())
                cout << "Level too low\n";
            else
            {
                player.spend_macca(Shop[action-1].get_cost());
                player.newItem(Shop[action-1].get_product());
            }
        }
        cout << "Do you want to buy items?\n1: Yes  2: No\n";
        cin >> action;
    }
}

void Game::useItems(){
    int action = 0;
    cout << "Do you want to use an item?\n1: Yes 2: No\n";
    cin >> action;
    while(action == 1)
    {
        cout << "0: Go back" << '\n';
        player.printItems();
        cin >> action;
        if(action > 0)
            player.useItem(action-1);
        cout << "Do you want to use an item?\n1: Yes 2: No\n";
        cin >> action;
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