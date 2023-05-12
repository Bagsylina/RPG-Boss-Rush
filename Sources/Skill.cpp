#include "../Headers/Skill.h"

//citire si afisare
std::istream& operator>>(std::istream& in, Skill& s)
{
    in >> s.name >> s.type >> s.base_damage >> s.MP_cost >> s.hit_rate >> s.critical_rate;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Skill& s)
{
    s.print(out);
    return out;
}

Skill& Skill::operator = (const Skill& other)
{
    name = other.name;
    type = other.type;
    base_damage = other.base_damage;
    MP_cost = other.MP_cost;
    hit_rate = other.hit_rate;
    critical_rate = other.critical_rate;
    return *this;
}

void Skill::print(std::ostream& where) const{
    where << name << '\n' << "Deals " << base_damage << ' ' << Skill::Types[type] << ". Costs " << MP_cost << " MP. Has a hit rate of " << hit_rate*100 << "% and critical rate of " << critical_rate*100 << '%';
}

int Skill::itemType() const {return 1;}

//geterts
int Skill::get_type() const{return type;}
int Skill::get_damage() const{return base_damage;}
int Skill::get_MP_cost() const{return MP_cost;}
double Skill::get_hit_rate() const{return hit_rate;}
double Skill::get_critical_rate() const{return critical_rate;}
