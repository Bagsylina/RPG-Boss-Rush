//
// Created by Anghel Fabian on 19/04/2023.
//

#include "../Headers/Player.h"

//getters
int Player::get_macca() const{return macca;}
int Player::get_nr_items() const{return inventory.size();}
Item Player::getItem(const int i) const{return *inventory[i];}
Accessory Player::getAccessory() const{return accessory;}
Armour Player::getArmour() const {return armour;}

/*void Player::printSkills() {
    cout << skill_list.size() << '\n';
    for(int i = 0; i <= skill_list.size(); i++)
        cout << i + 1 << ": " <<  skill_list[i] << '\n';
}*/

void Player::forgetSkill(const int i){skill_list.erase(skill_list.begin()+i);} //erase a skill

void Player::spend_macca(int x){macca-=x;}

void Player::newItem(Item* item){inventory.push_back(item);} //get an item

void Player::deleteItem(int i){inventory.erase(inventory.begin() + i);}

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

void Player::battle_rewards(const int macca_gained, const int xp_gained){
    macca += macca_gained;
    xp += xp_gained;
    while(xp > 1000)
    {
        xp -= 1000;
        level++;
    }
}

bool Player::UseSkill(const Skill& s, Entity& enemy, const bool guard = false) //an entity uses a certain skill on another entity that may or may not be guarding
{
    current_MP -= s.get_MP_cost(); //skill uses a certain amount of MP
    double hitr = s.get_hit_rate() * (agility / enemy.get_agi()); //calculating the hir rate, taking agility into account
    srand(time(0));
    int r = rand() % 1000, type = s.get_type(), weak = enemy.get_weakness(type); //generate a random number that determines if the skill hits and get the type of the move and the enemies weakness to the type
    if(r >= hitr*1000 || weak == 2) //do nothing if move misses or the skill is nulled by the enemy
        return false;
    else {
        int attack = 0;
        if (type == 0) //get the attack depending of the type of the move
            attack = strength;
        else if (type < 3)
            attack = (strength + dexterity) / 2;
        else
            attack = dexterity;
        double dmg = s.get_damage() * attack * min((double)(1), (double)(1+(double)(level)/100)); //get the base damage of the move taking into account the attack stat and the level
        if(accessory.get_type() == type) //buff the damage if the type is buffed by the accessory
            dmg *= (1 + accessory.get_buff());
        srand(time(0));
        r = rand() % 1000; //generate a random number that determines if the skill is a critical hit
        hitr = s.get_critical_rate() * (luck / enemy.get_lck());
        bool extraTurn = false; //entity gets an extra turn if the enemy is weak to the skill
        if(guard) //decrease damage if enemy is guarding
            dmg *= 0.3;
        if(r < hitr*1000) { //increase damage if skill is a critical hit
            cout << "A critical hit!\n";
            dmg *= 1.2;
            extraTurn = true;
        }
        if(weak == -1){ //increase damage if enemy is weak to the skill
            dmg *= 1.2;
            extraTurn = true;
        }
        else if(weak == 1) //decrease damage if the enemy resists the skill
            dmg *= 0.8;
        else if(weak == 4) { //heal instead of do damage if enemy absorbs the skill
            dmg *= -0.5;
            extraTurn = false;
        }
        if(weak != 3) { //do damage to the enemy if it doesn't reflect the skill
            dmg /= enemy.get_vit();
            enemy.takedamage(dmg);
        }
        else{ //do damage to the entity that uses the skill if the enemy reflets the type of the skill
            extraTurn = false;
            dmg /= enemy.get_vit();
            if(weakness_chart[type]==-1)
                dmg *= 1.2;
            else if(weakness_chart[type]==1)
                dmg *= 0.8;
            else if(weakness_chart[type]==4)
                dmg *= -0.5;
            else if(weakness_chart[type]>2)
                dmg = 0;
            takedamage(dmg);
        }
        return extraTurn;//returns if the entity gets a extra turn or not after using the skill
    }
}

void Player::useItem(int i){
    Item* p = inventory[i];
    int type = p->itemType();
    if(type == 1)
    {
        Skill* s = dynamic_cast<Skill*>(p);
        cout << "Choose a skill to forget:\n";
        printSkills();
        int action = 0;
        std::cin >> action;
        Skill s1 = get_skill(action-1);
        Item *p1 = new Skill(s1);
        newItem(p1);
        forgetSkill(action-1);
        learnSkill(*s);
    }
    else if(type == 2)
    {
        Accessory* a = dynamic_cast<Accessory*>(p);
        Accessory a1 = getAccessory();
        Item *p1 = new Accessory(a1);
        newItem(p1);
        equip_accessory(*a);
    }
    else if(type == 3)
    {
        Armour* a = dynamic_cast<Armour*>(p);
        Armour a1 = getArmour();
        Item *p1 = new Armour(a1);
        newItem(p1);
        equip_armour(*a);
    }
    else if(type == 4)
    {
        Consumable* c = dynamic_cast<Consumable*>(p);
        heal(c->get_HP_heal(), c->get_MP_heal());
    }
    deleteItem(i);
};

void Player::printItems(){
    int n = inventory.size();
    for(int i = 0; i < n; i++)
        cout << i+1 <<": " << *inventory[i] << '\n';
}