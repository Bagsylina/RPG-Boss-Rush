#include "../Headers/Player.h"

std::ostream& operator<<(std::ostream& out, const Player& e){
    e.afisBasicStats(out);
    out << "Strength: " << e.strength << " Dexterity: " << e.dexterity << " Vitality: " << e.vitality << " Agility: "<< e.agility << " Luck: " << e.luck << '\n';
    out << "Number of skills: " << e.skill_list.size() << '\n';
    e.printSkills(out);
    for(int i = 0; i < 8; i++)
    {
        switch (e.weakness_chart[i]) {
            case -1: out << "Weak to "; break;
            case 0: out << "Normal damage from "; break;
            case 1: out << "Resistant to "; break;
            case 2: out << "No damage from "; break;
            case 3: out << "Reflects "; break;
            case 4: out << "Absorbs "; break;
        }
        out << Player::Types[i] << '\n';
    }
    out << "Armour: " << e.armour << '\n';
    out << "Accessory: " << e.accessory << '\n';
    out << "Number of items in inventory: " << e.inventory.size() << '\n';
    e.printItems(out);
    return out;
}

void Player::printItems(std::ostream& where) const{ // prints the items in the players inventory
    int n = inventory.size();
    for(int i = 0; i < n; i++)
        where << i+1 <<": " << *inventory[i] << '\n';
}

//getters
int Player::get_macca() const{return macca;}
int Player::get_nr_items() const{return inventory.size();}
Accessory Player::getAccessory() const{return accessory;}
Armour Player::getArmour() const {return armour;}


void Player::spend_macca(int x){macca-=x;}

void Player::newItem(Item& item){
    inventory.push_back(item.clone());
} //get an item

void Player::deleteItem(int i){
    delete inventory[i];
    inventory.erase(inventory.begin() + i);
}

void Player::equip_armour(const Armour& a) { //equip armour and change stats to fit the bonus stats from the armour
    HP += (a.get_bHP() - armour.get_bHP());
    MP += (a.get_bMP() - armour.get_bMP());
    strength += (a.get_bstr() - armour.get_bstr());
    dexterity += (a.get_bdex() - armour.get_bdex());
    vitality += (a.get_bvit() - armour.get_bvit());
    agility += (a.get_bagi() - armour.get_bagi());
    luck += (a.get_blck() - armour.get_blck());
    armour = a;
}
void Player::equip_accessory(const Accessory& a){accessory = a;} //equip accessory

void Player::battle_rewards(const int macca_gained, const int xp_gained){ //player gains macca, xp and level after winning a battle
    macca += macca_gained;
    xp += xp_gained;
    while(xp > 1000)
    {
        xp -= 1000;
        level++;
        LevelUp();
    }
}

bool Player::UseSkill(const Skill& s, Entity& enemy, const bool guard = false) //an entity uses a certain skill on another entity that may or may not be guarding
{
    current_MP -= s.get_MP_cost(); //skill uses a certain amount of MP
    double hitr = s.get_hit_rate() * (agility / enemy.get_agi()); //calculating the hir rate, taking agility into account
    srand(time(0));
    int r = rand() % 1000, type = s.get_type(), weak = enemy.get_weakness(type); //generate a random number that determines if the skill hits and get the type of the move and the enemies weakness to the type
    if(r >= hitr*1000 || weak == 2) //do nothing if move misses or the skill is nulled by the enemy
    {
        std::cout<<"Missed!\n";
        return false;
    }
    else {
        int attack = 0;
        switch(type){
            case 0: attack = strength; break; //physical attacks use strength
            case 1: case 2: attack = (strength + dexterity) / 2; break; //pierce and projectile attacks use both strength and dexterity
            default: attack = dexterity; break; //all other attacks use only dexterity
        }
        double dmg = s.get_damage() * attack * std::min(1.0, (double)(1.0+(double)(level)/100)); //get the base damage of the move taking into account the attack stat and the level
        if(accessory.get_type() == type) //buff the damage if the type is buffed by the accessory
            dmg *= (1 + accessory.get_buff());
        srand(time(0));
        r = rand() % 1000; //generate a random number that determines if the skill is a critical hit
        hitr = s.get_critical_rate() * (luck / enemy.get_lck());
        bool extraTurn = false; //entity gets an extra turn if the enemy is weak to the skill
        if(guard) //decrease damage if enemy is guarding
            dmg *= 0.3;
        if(r < hitr*1000) { //increase damage if skill is a critical hit
            std::cout << "A critical hit!\n";
            dmg *= 1.2;
            extraTurn = true;
        }
        switch(weak){
            case -1: dmg *= 1.2; extraTurn = true; break; //increase damage if enemy is weak to the skill
            case 1: dmg *= 0.8; break; //heal instead of do damage if enemy absorbs the skill
            case 4: dmg = -0.5; extraTurn = false; break; //do damage to the enemy if it doesn't reflect the skill
        }
        if(weak != 3) { //do damage to the enemy if it doesn't reflect the skill
            dmg /= enemy.get_vit();
            enemy.takedamage(dmg);
        }
        else{ //do damage to the entity that uses the skill if the enemy reflets the type of the skill
            extraTurn = false;
            dmg /= vitality;
            switch(weakness_chart[type]){
                case -1: dmg *= 1.2; break;
                case 1: dmg *= 0.8; break;
                case 2: case 3: dmg = 0; break;
                case 4: dmg *= -0.5; break;
            }
            takedamage(dmg);
        }
        return extraTurn; //returns if the entity gets a extra turn or not after using the skill
    }
}


//player using an item from inventory
void Player::useItem(int i){
    Item* p = inventory[i];
    p->useThis(*this);
    deleteItem(i);
};

void Player::LevelUp() {
    std::cout << "Choose a stat to raise:\n1: Strength\n2: Dexterity\n3: Vitality\n4: Agility\n5: Luck\n";
    int action = 0;
    std::cin >> action;
    try{
        if(action < 1 || action > 5)
            throw InvalidInput();
        else switch(action){
            case 1: strength++; break;
            case 2: dexterity++; break;
            case 3: vitality++; break;
            case 4: agility++; break;
            case 5: luck++; break;
        }
    }
    catch(InvalidInput& e){
        std::cout << e.what();
        std::cin.clear();
        std::cin.ignore(256,'\n');
    }
}