#include "../Headers/Entity.h"

const std::vector <std::string> Entity::Types = {"Physical", "Pierce", "Projectile", "Fire", "Water", "Electricity", "Earth", "Wind"};

std::istream& operator>>(std::istream& in, Entity& e)
{
    in >> e.name >> e.level >> e.HP >> e.MP >> e.strength >> e.dexterity >> e.vitality >> e.agility >> e.luck;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Entity& e)
{
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
        out << Entity::Types[i] << '\n';
    }
    return out;
}

void Entity::afisBasicStats(std::ostream& where) const{
    where << name << '\n' << "Level " << level << '\n';
    where << "HP: " << current_HP << '/' << HP << " MP: "<< current_MP << '/' << MP << '\n';
}

void Entity::printSkills(std::ostream& where) const{
    int nr = (int)(skill_list.size());
    for(int i = 0; i < nr; i++)
        where << i + 1 << ": " <<  skill_list[i] << '\n';
}

void Entity::printTypes(std::ostream& where) {
    int nr = (int)(Types.size());
    for(int i = 0; i < nr; i++)
        where << i + 1 << ": " << Types[i] << '\n';
}

int Entity::get_level() const{return level;}
int Entity::get_curHP() const{return current_HP;}
int Entity::get_curMP() const{return current_MP;}
int Entity::get_vit() const{return vitality;}
int Entity::get_agi() const{return agility;}
int Entity::get_lck() const{return luck;}
int Entity::get_weakness(const int type) const{return weakness_chart[type];}
int Entity::get_nr_skills() const{return (int)(skill_list.size());}
Skill Entity::get_skill(const int i) const{return skill_list[i];}


void Entity::changeWeakness(const int type,const int weak){weakness_chart[type]=weak;} //change a weakness

void Entity::takedamage(const int damage){//entity takes a certain amount of damage
    current_HP -= damage;
    current_HP = std::max(current_HP,0);
    current_HP = std::min(current_HP, HP);
    std::cout << "Dealt "<<damage<<" to "<<name<<".\n";
}


void Entity::learnSkill(const Skill& s) {skill_list.push_back(s);} //learn a new skill

void Entity::forgetSkill(const int i){skill_list.erase(skill_list.begin()+i);} //erase a skill

bool Entity::UseSkill(const Skill& s, Entity& enemy, const bool guard) //an entity uses a certain skill on another entity that may or may not be guarding
{
    current_MP -= s.get_MP_cost(); //skill uses a certain amount of MP
    double hitr = s.get_hit_rate() * ((double)(agility) / (double)(enemy.get_agi())); //calculating the hir rate, taking agility into account
    int r = rand() % 1000, type = s.get_type(), weak = enemy.get_weakness(type); //generate a random number that determines if the skill hits and get the type of the move and the enemies weakness to the type
    if(r >= hitr*1000 || weak == 2) //do nothing if move misses or the skill is nulled by the enemy
    {
        std::cout << "Missed!\n";
        return false;
    }
    else {
        int attack = 0;
        switch(type){
            case 0: attack = strength; break; //physical attacks use strength
            case 1: case 2: attack = (strength + dexterity) / 2; break; //pierce and projectile attacks use both strength and dexterity
            default: attack = dexterity; break; //all other attacks use only dexterity
        }
        double dmg = s.get_damage() * attack * std::min(1.0, (double)(1+(double)(level)/100)); //get the base damage of the move taking into account the attack stat and the level
        r = rand() % 1000; //generate a random number that determines if the skill is a critical hit
        hitr = s.get_critical_rate() * ((double)(luck) / (double)(enemy.get_lck()));
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
            default: break;
        }
        if(weak != 3) { //do damage to the enemy if it doesn't reflect the skill
            dmg /= enemy.get_vit();
            enemy.takedamage((int)(dmg));
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
            takedamage((int)(dmg));
        }
        return extraTurn;//returns if the entity gets a extra turn or not after using the skill
    }
}


void Entity::guardHeal(){current_MP = std::min(MP, current_MP + MP / 7); current_HP = std::min(HP, current_HP + HP / 20);} //heal MP and HP if guarding
void Entity::heal(int heal_HP, int heal_MP){current_MP = std::min(MP, current_MP + heal_MP); current_HP = std::min(HP, current_HP + heal_HP);}