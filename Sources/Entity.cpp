//
// Created by Anghel Fabian on 19/04/2023.
//

#include "../Headers/Entity.h"


void Entity::afisBasicStats(){
    cout << name << '\n' << "Level " << level << '\n';
    cout << "HP: " << current_HP << '/' << HP << " MP: "<< current_MP << '/' << MP << '\n';
}

int Entity::get_level() const{return level;}
int Entity::get_curHP() const{return current_HP;}
int Entity::get_curMP() const{return current_MP;}
int Entity::get_vit() const{return vitality;}
int Entity::get_agi() const{return agility;}
int Entity::get_lck() const{return luck;}
int Entity::get_weakness(const int type) const{return weakness_chart[type];}
int Entity::get_nr_skills() const{return skill_list.size();}
Skill Entity::get_skill(const int i) const{return skill_list[i];}

void Entity::changeWeakness(const int type,const int weak){weakness_chart[type]=weak;} //change a weakness

void Entity::takedamage(const int damage){//entity takes a certain amount of damage
    current_HP -= damage;
    current_HP=max(current_HP,0);
    current_HP=min(current_HP, HP);
    cout << "Dealt "<<damage<<" to "<<name<<".\n";
}

void Entity::learnSkill(const Skill& s) {skill_list.push_back(s);} //learn a new skill

void Entity::printSkills() {
    //cout << skill_list.size() << '\n';
    for(int i = 0; i < skill_list.size(); i++)
        cout << i + 1 << ": " <<  skill_list[i] << '\n';
}

void Entity::forgetSkill(const int i){skill_list.erase(skill_list.begin()+i);} //erase a skill

void Entity::guardHeal(){current_MP = min(MP, current_MP + MP / 7); current_HP = min(HP, current_HP + HP / 20);} //heal MP and HP if guarding

void Entity::heal(int heal_HP, int heal_MP){current_MP = min(MP, current_MP + heal_MP); current_HP = min(HP, current_HP + heal_HP);}

bool Entity::UseSkill(const Skill& s, Entity& enemy, const bool guard = false) //an entity uses a certain skill on another entity that may or may not be guarding
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