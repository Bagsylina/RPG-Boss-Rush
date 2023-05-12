#include "../Headers/Armour.h"

std::ostream& operator<<(std::ostream& out, const Armour& ar)
{
    ar.print(out);
    return out;
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

int Armour::itemType() const{return 3;}

//getters
int Armour::get_bHP() const{return bonus_HP;}
int Armour::get_bMP() const{return bonus_MP;}
int Armour::get_bstr() const{return bonus_strength;}
int Armour::get_bdex() const{return bonus_dexterity;}
int Armour::get_bvit() const{return bonus_vitality;}
int Armour::get_bagi() const{return bonus_agility;}
int Armour::get_blck() const{return bonus_luck;}
