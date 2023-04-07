#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

const vector <string> Types = {"Physical", "Pierce", "Projectile", "Fire", "Water", "Electricity", "Earth", "Wind"};
const vector <string> Stats = {"HP", "MP", "Strength", "Dexterity", "Vitality", "Agility", "Luck"};

class Skill{
    string name;
    int type, base_damage, MP_cost;
    float hit_rate, critical_rate;

public:

    // constructor
    Skill(string _name = "", const int _type = 0, const int _base_damage = 0, const int _MP_cost = 0, const float _hit_rate = 1, const float _critical_rate = 0.01): name(_name), type(_type), base_damage(_base_damage), MP_cost(_MP_cost), hit_rate(_hit_rate), critical_rate(_critical_rate){}

    //constructor de copiere
    Skill(const Skill & other): name(other.name), type(other.type), base_damage(other.base_damage), MP_cost(other.MP_cost), hit_rate(other.hit_rate), critical_rate(other.critical_rate){}

    //destructor
    ~Skill(){}

    //citire si afisare
    friend istream& operator>>(istream& in, Skill& s)
    {
        in >> s.name >> s.type >> s.base_damage >> s.MP_cost >> s.hit_rate >> s.critical_rate;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Skill& s)
    {
        return out << s.name << '\n' << "Deals " << s.base_damage << ' ' << Types[s.type] << ". Costs " << s.MP_cost << " MP. Has a hit rate of " << s.hit_rate << "and critical rate of " << s.critical_rate;
    }

    //operator de copiere
    Skill& operator=(const Skill& other)
    {
        name = other.name;
        type = other.type;
        base_damage = other.base_damage;
        MP_cost = other.MP_cost;
        hit_rate = other.hit_rate;
        critical_rate = other.critical_rate;
    }

    //gets
    const string get_name(){return name;}
    const int get_type(){return type;}
    const int get_damage(){return base_damage;}
    const int get_MP_cost(){return MP_cost;}
    const float get_hit_rate(){return hit_rate;}
    const float get_critical_rate(){return critical_rate;}

    //sets
    void set_name(string x){name=x;}
    void set_type(int x){type=x;}
    void set_damage(int x){base_damage=x;}
    void set_MP_cost(int x){MP_cost=x;}
    void set_hit_rate(float x){hit_rate=x;}
    void set_critical_rate(float x){critical_rate=x;}
};

class Accessory{
    string name;
    int type_buff;
    float buff_percentage;

public:
    //constructor
    Accessory(const string _name = "Basic Ring", const int _type_buff = 0, const int _buff_percentage = 0): name(_name), type_buff(_type_buff), buff_percentage(_buff_percentage){}
    //citire si afisare
    friend istream& operator>>(istream& in, Accessory& a)
    {
        return in >> a.name >> a.type_buff >> a.buff_percentage;
    }

    friend ostream& operator<<(ostream& out, const Accessory& a)
    {
        return out << a.name << '\n' << Types[a.type_buff] << " buffed by " << a.buff_percentage << '%';
    }

    //gets
    const int get_type(){return type_buff;}
    const float get_buff(){return buff_percentage;}

    //sets
    void set_name(string x){name=x;}
    void set_type(int x){type_buff=x;}
    void set_buff(float x){buff_percentage=x;}
};

class Armour{
    string name;
    int bonus_HP, bonus_MP, bonus_strength, bonus_dexterity, bonus_vitality, bonus_agility, bonus_luck;
public:
    //constructor
    Armour(const string _name = "Basic Armour", const int _bonus_HP = 0, const int _bonus_MP = 0, const int _bonus_strength = 0, const int _bonus_dexterity = 0, const int _bonus_vitality = 0, const int _bonus_agility = 0, const int _bonus_luck = 0): name(_name), bonus_HP(_bonus_HP), bonus_MP(_bonus_MP), bonus_strength(_bonus_strength), bonus_dexterity(_bonus_dexterity), bonus_vitality(_bonus_vitality), bonus_agility(_bonus_agility), bonus_luck(_bonus_luck) {}
    //citire si afisare
    friend istream& operator>>(istream& in, Armour& a)
    {
        return in >> a.name >> a.bonus_HP >> a.bonus_MP >> a.bonus_strength >> a.bonus_dexterity >> a.bonus_vitality >> a.bonus_agility >> a.bonus_luck;
    }

    friend ostream& operator<<(ostream& out, const Armour& ar)
    {
        out << ar.name;
        if(ar.bonus_HP)
           out << '\n' << "Bonus HP: " << ar.bonus_HP;
        if(ar.bonus_MP)
            out << '\n' << "Bonus MP: " << ar.bonus_MP;
        if(ar.bonus_strength)
            out << '\n' << "Bonus Strength: " << ar.bonus_strength;
        if(ar.bonus_dexterity)
            out << '\n' << "Bonus : " << ar.bonus_dexterity;
        if(ar.bonus_vitality)
            out << '\n' << "Bonus Vitality: " << ar.bonus_vitality;
        if(ar.bonus_agility)
            out << '\n' << "Bonus Agility: " << ar.bonus_agility;
        if(ar.bonus_luck)
            out << '\n' << "Bonus Luck: " << ar.bonus_luck;
        return out;
    }

    //gets
    const int get_bHP(){return bonus_HP;}
    const int get_bMP(){return bonus_MP;}
    const int get_bstr(){return bonus_strength;}
    const int get_bdex(){return bonus_dexterity;}
    const int get_bvit(){return bonus_vitality;}
    const int get_bagi(){return bonus_agility;}
    const int get_blck(){return bonus_luck;}

    //sets
    void set_name(string x){name=x;}
    void get_bHP(int x){bonus_HP=x;}
    void get_bMP(int x){bonus_MP=x;}
    void get_bstr(int x){bonus_strength=x;}
    void get_bdex(int x){bonus_dexterity=x;}
    void get_bvit(int x){bonus_vitality=x;}
    void get_bagi(int x){bonus_agility=x;}
    void get_blck(int x){bonus_luck=x;}
};

class Consumable{
    string name;
    int HP_heal, MP_heal;
public:
    //constructor
    Consumable(const string _name = "Food", const int _HP_heal = 0, const int _MP_heal = 0): name(_name), HP_heal(_HP_heal), MP_heal(_MP_heal) {}
    //citire si afisare
    friend istream& operator>>(istream& in, Consumable& c)
    {
        return in >> c.name >> c.HP_heal >> c.MP_heal;
    }
    friend ostream& operator<<(ostream& out, const Consumable& c)
    {
        out << c.name << "\n Heals ";
        if(c.MP_heal == 0)
            out << c.HP_heal << " HP";
        else if (c.HP_heal == 0)
            out << c.MP_heal << " MP";
        else
            out << c.HP_heal << " HP and " << c.MP_heal << " MP";
        return out;
    }

    //gets
    const string get_name(){return name;}
    const int get_HP_heal(){return HP_heal;}
    const int get_MP_heal(){return MP_heal;}

    //sets
    void set_name(string x){name=x;}
    void set_HP_heal(int x){HP_heal=x;}
    void set_MP_heal(int x){MP_heal=x;}
};

class Entity{
    string name;
    vector <Skill> skill_list;
    int level, HP, MP, macca, strength, dexterity, vitality, agility, luck;
    int current_HP, current_MP;
    int weakness_chart[8];
    Accessory accessory;
    Armour armour;
    int nr_items;
    vector <Consumable> inventory;

public:
    //constructor
    Entity(const string _name = "Demon", const int _level = 1, const int _HP = 100, const int _MP = 30, const int _macca = 0, const int _strength = 3, const int _dexterity = 3, const int _vitality = 3, const int _agility = 3, const int _luck = 3): name(_name), level(_level), HP(_HP), MP(_MP), macca(_macca), strength(_strength), dexterity(_dexterity), vitality(_vitality), agility(_agility), luck(_luck)
    {
        current_HP = HP;
        current_MP = MP;
        nr_items = 0;
        for(int i = 0; i <= 7; i++)
            weakness_chart[i] = 0;
    }
    //citire si afisare
    friend istream& operator>>(istream& in, Entity& e)
    {
        return in >> e.name >> e.level >> e.HP >> e.MP >> e.strength >> e.dexterity >> e.vitality >> e.agility >> e.luck;
    }

    friend ostream& operator<<(ostream& out, const Entity& e)
    {
        out << e.name << '\n' << "Level " << e.level << '\n';
        out << "HP: " << e.current_HP << '/' << e.HP << " MP: "<< e.current_MP << '/' << e.MP << '\n';
        out << "Strength: " << e.strength << " Dexterity: " << e.dexterity << " Vitality: " << e.vitality << " Agility: "<< e.agility << " Luck: " << e.luck << '\n';
        out << "Number of skills: " << e.skill_list.size() << '\n';
        for(int i = 0; i < e.skill_list.size(); i++)
            out << e.skill_list[i] << '\n';
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
            out << Types[i] << '\n';
        }
        out << "Armour: " << e.armour << '\n';
        out << "Accessory: " << e.accessory << '\n';
        out << "Number of items in inventory: " << e.nr_items << '\n';
        for(int i = 0; i < e.nr_items; i++)
            out << e.inventory[i] << '\n';
        return out;
    }

    void afisBasicStats(){
        cout << name << '\n' << "Level " << level << '\n';
        cout << "HP: " << current_HP << '/' << HP << " MP: "<< current_MP << '/' << MP << '\n';
    }

    //getters
    const int get_lvl(){return level;}
    const int get_HP(){return HP;}
    const int get_MP(){return MP;}
    const int get_curHP(){return current_HP;}
    const int get_curMP(){return current_MP;}
    const int get_str(){return strength;}
    const int get_dex(){return dexterity;}
    const int get_vit(){return vitality;}
    const int get_agi(){return agility;}
    const int get_lck(){return luck;}
    const int get_weakness(int type){return weakness_chart[type];}
    const int get_nr_skills(){return skill_list.size();}
    const Skill get_skill(int i){return skill_list[i];}
    const int get_nr_items(){return inventory.size();}
    const Consumable get_item(int i){return inventory[i];}

    //use skill

    void takedamage(int damage){current_HP -= damage; current_HP=max(current_HP,0); current_HP=min(current_HP, HP);} //entity takes a certain amount of damage

    bool learnSkill(Skill s) //learn a new skill
    {
        if(skill_list.size() < 4)
        {
            skill_list.push_back(s);
            return true;
        }
        return false;
    }

    void forgetSkill(int i){skill_list.erase(skill_list.begin()+i);} //erase a skill

    void equip_armour(Armour a) { //equip armour and change stats to fit the bonus stats from the armour
        HP += (a.get_bHP() - armour.get_bHP());
        MP += (a.get_bMP() - armour.get_bMP());
        strength += (a.get_bstr() - armour.get_bstr());
        dexterity += (a.get_bdex() - armour.get_bdex());
        vitality += (a.get_bvit() - armour.get_bvit());
        agility += (a.get_bagi() - armour.get_bagi());
        luck += (a.get_blck() - armour.get_blck());
        armour = a;
    }

    void equip_accessory(Accessory a){accessory = a;} //equip accessory

    void useItem(int i){ //use a consumable and heal HP and MP
        current_HP = min(HP, current_HP + inventory[i].get_HP_heal());
        current_MP = min(MP, current_MP + inventory[i].get_MP_heal());
        inventory.erase(inventory.begin()+i);
    }

    void guardHeal(){current_MP = min(MP, current_MP + MP / 7); current_HP = min(HP, current_HP + HP / 20);} //heal MP and HP if guarding

    bool UseSkill(Skill s, Entity& enemy, bool guard = false) //an entity uses a certain skill on another entity that may or may not be guarding
    {
        current_MP -= s.get_MP_cost(); //skill uses a certain amount of MP
        float hitr = s.get_hit_rate() * (agility / enemy.get_agi()); //calculating the hir rate, taking agility into account
        int r = rand() % 1000, type = s.get_type(), weak = enemy.get_weakness(type); //generate a random number that determines if the skill hits and get the type of the move and the enemies weakness to the type
        if(r >= hitr*1000 || weak == 2) //do nothing if move misses or the skill is nulled by the enemy
            return false;
        if(r < hitr*1000) {
            int attack = 0;
            if (type == 0) //get the attack depending of the type of the move
                attack = strength;
            else if (type < 3)
                attack = (strength + dexterity) / 2;
            else
                attack = dexterity;
            float dmg = s.get_damage() * attack * min((float)(1), (float)(1+(float)(level)/100)); //get the base damage of the move taking into account the attack stat and the level
            if(accessory.get_type() == type) //buff the damage if the type is buffed by the accessory
                dmg *= accessory.get_buff();
            r = rand() % 1000; //generate a random number that determines if the skill is a critical hit
            hitr = s.get_critical_rate() * (luck / enemy.get_lck());
            bool extraTurn = false; //entity gets an extra turn if the enemy is weak to the skill
            if(guard) //decrease damage if enemy is guarding
                dmg *= 0.3;
            if(r < hitr*1000) { //increase damage if skill is a critical hit
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
};

class Battle{
    Entity player, enemy;
    bool playerGuard = false, enemyGuard = false;

public:
    Battle(Entity _player, Entity _enemy): player(_player), enemy(_enemy) {}

    bool playerAction(int action){ //player action
        bool extraTurn = false;
        if(action == 1) //attack the enemy
        {
            cout << "Choose attack\n"; //printing the available skills
            int nr = player.get_nr_skills();
            Skill s;
            for(int i=0;i<nr;i++) {
                s = player.get_skill(i);
                cout << i+1 << ": " << s.get_name() << '\n';
            }
            cin >> action; //choosing the skill
            s = player.get_skill(action-1);
            if(player.get_curMP() >= s.get_MP_cost()) //using the skill if there is enough MP
                extraTurn = player.UseSkill(s, enemy, enemyGuard);
        }
        else if(action == 2) //guarding
        {
            playerGuard = true;
            player.guardHeal();
        }
        else if(action == 3) { //using an item
            cout << "Choose item\n"; //printing available items
            int nr = player.get_nr_items();
            if(nr == 0)
                cout << "No items\n";
            else {
                Consumable c;
                for (int i = 0; i < nr; i++) {
                    c = player.get_item(i);
                    cout << i + 1 << ": " << c.get_name() << '\n';
                }
                cin >> action; //choosing an item
                player.useItem(action - 1);
            }
        }
        else // showing the full stats of the player and enemy and getting an extra turn
        {
            cout << player << '\n' << enemy << '\n';
            extraTurn = true;
        }
        return extraTurn; //returns if the player got an extra turn after his action
    }
    void battleTurnPlayer(){ //player turn
        playerGuard = false;
        cout << "Choose action\n" << "1: Attack\n" << "2: Guard\n" << "3: Item\n" << "4: Stats\n";
        int action;
        cin >> action; //choosing an action
        bool extraTurn = playerAction(action);
        if(extraTurn = true && enemy.get_curHP()) //another action if the player got an extra turn
        {
            player.afisBasicStats();
            enemy.afisBasicStats();
            cout << "Choose action\n" << "1: Attack\n" << "2: Guard\n" << "3: Item\n" << "4: Stats\n";
            cin >> action;
            extraTurn = playerAction(action);
        }
    }

    void battleTurnEnemy(){ //enemy turn
        enemyGuard = false;
        int r = rand() % 5; //random chance for fighting or guarding
        if(r == 4) {
            enemyGuard = true;
            enemy.guardHeal();
        }
        else
        {
            r = rand() % enemy.get_nr_skills(); //use random skill
            Skill s = enemy.get_skill(r);
            bool extraTurn = false;
            if(enemy.get_curMP() >= s.get_MP_cost())
                extraTurn = enemy.UseSkill(s, player, playerGuard);
            if(extraTurn) //another action if the enemy got an extra turn
            {
                player.afisBasicStats();
                enemy.afisBasicStats();
                r = rand() % 5; //random chance for fighting or guarding
                if(r == 4)
                    enemyGuard = true;
                else
                {
                    r = rand() % enemy.get_nr_skills(); //use random skill
                    Skill s = enemy.get_skill(r);
                    if(enemy.get_curMP() >= s.get_MP_cost())
                        extraTurn = enemy.UseSkill(s, player, playerGuard);
                }
            }
        }
    }

    void battle(){
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
    }
};

int main() {
    srand(time(0));
    Entity pixie("Pixie", 3, 300, 34, 100, 4, 7, 3, 6, 4);
    cout << pixie << '\n';
    Skill agi("Agi", 3, 20, 8, 1, 0.2);
    cout << pixie.learnSkill(agi) << '\n';
    Entity pixie2 = pixie;
    cout << pixie.UseSkill(agi, pixie2, false) << '\n';
    pixie.afisBasicStats();
    cout << '\n';
    pixie2.afisBasicStats();
    Battle b1(pixie, pixie2);
    b1.battle();
    return 0;
}