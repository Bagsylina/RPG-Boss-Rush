#include "../Headers/Armour.h"
#include "../Headers/Player.h"

Armour::Armour(const std::string &aname, const int abonus_HP, const int abonus_MP, const int abonus_strength,
               const int abonus_dexterity, const int abonus_vitality, const int abonus_agility, const int abonus_luck) : Item(aname), bonus_HP(abonus_HP), bonus_MP(abonus_MP), bonus_strength(abonus_strength), bonus_dexterity(abonus_dexterity), bonus_vitality(abonus_vitality), bonus_agility(abonus_agility), bonus_luck(abonus_luck)
{
    if(bonus_HP < 0 || bonus_MP < 0 || bonus_strength < 0 || bonus_dexterity < 0 || bonus_vitality < 0 || bonus_agility < 0 || bonus_luck < 0)
        throw InvalidStats("armour");
}

Item *Armour::clone() const {return new Armour(*this);}

std::istream &operator>>(std::istream &in, Armour &a) {
    in >> a.name >> a.bonus_HP >> a.bonus_MP >> a.bonus_strength >> a.bonus_dexterity >> a.bonus_vitality >> a.bonus_agility >> a.bonus_luck;
    return in;
}

void Armour::print(std::ostream& where) const{
    where << name;
    if(bonus_HP)
        where << '\n' << "Bonus HP: " << bonus_HP;
    if(bonus_MP)
        where << '\n' << "Bonus MP: " << bonus_MP;
    if(bonus_strength)
        where << '\n' << "Bonus Strength: " << bonus_strength;
    if(bonus_dexterity)
        where << '\n' << "Bonus Dexterity : " << bonus_dexterity;
    if(bonus_vitality)
        where << '\n' << "Bonus Vitality: " << bonus_vitality;
    if(bonus_agility)
        where << '\n' << "Bonus Agility: " << bonus_agility;
    if(bonus_luck)
        where << '\n' << "Bonus Luck: " << bonus_luck;
}

//getters
int Armour::get_bHP() const{return bonus_HP;}
int Armour::get_bMP() const{return bonus_MP;}
int Armour::get_bstr() const{return bonus_strength;}
int Armour::get_bdex() const{return bonus_dexterity;}
int Armour::get_bvit() const{return bonus_vitality;}
int Armour::get_bagi() const{return bonus_agility;}
int Armour::get_blck() const{return bonus_luck;}

void Armour::useThis(Player& p){
    Armour a1 = p.getArmour();
    p.newItem(a1);
    p.equip_armour(*this);
}
