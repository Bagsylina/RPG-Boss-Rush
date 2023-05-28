#include "../Headers/Consumable.h"
#include "../Headers/Player.h"

Consumable::Consumable(const std::string &cname, const int cHP_heal, const int cMP_heal) : Item(cname), HP_heal(cHP_heal), MP_heal(cMP_heal) {
    if(HP_heal < 0 || MP_heal < 0 || HP_heal + MP_heal <= 0)
        throw InvalidHeal();
}

Item *Consumable::clone() const {return new Consumable(*this);}

std::istream& operator>>(std::istream& in, Consumable& c)
{
    in >> c.name >> c.HP_heal >> c.MP_heal;
    return in;
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

//getters
int Consumable::get_HP_heal() const{return HP_heal;}
int Consumable::get_MP_heal() const{return MP_heal;}

void Consumable::useThis(Player& p){
    p.heal(get_HP_heal(), get_MP_heal());
}
