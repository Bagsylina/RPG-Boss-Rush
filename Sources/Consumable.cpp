#include "../Headers/Consumable.h"

std::istream& operator>>(std::istream& in, Consumable& c)
{
    in >> c.name >> c.HP_heal >> c.MP_heal;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Consumable& c)
{
    c.print(out);
    return out;
}

void Consumable::print(std::ostream& where) const{
    where << name << "\nHeals ";
    if(MP_heal == 0)
        where << HP_heal << " HP";
    else if (HP_heal == 0)
        where << MP_heal << " MP";
    else
        where << HP_heal << " HP and " << MP_heal << " MP";
}

int Consumable::itemType() const {return 4;}

//getters
int Consumable::get_HP_heal() const{return HP_heal;}
int Consumable::get_MP_heal() const{return MP_heal;}
