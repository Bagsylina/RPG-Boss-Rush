//
// Created by Anghel Fabian on 19/04/2023.
//

#include "../Headers/Skill.h"

//citire si afisare
std::istream& operator>>(std::istream& in, Skill& s)
{
    in >> s.name >> s.type >> s.base_damage >> s.MP_cost >> s.hit_rate >> s.critical_rate;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Skill& s)
{
    return out << s.name << '\n' << "Deals " << s.base_damage << ' ' << Types[s.type] << ". Costs " << s.MP_cost << " MP. Has a hit rate of " << s.hit_rate*100 << "% and critical rate of " << s.critical_rate*100 << '%';
}

//geterts
int Skill::get_type() const{return type;}
int Skill::get_damage() const{return base_damage;}
int Skill::get_MP_cost() const{return MP_cost;}
double Skill::get_hit_rate() const{return hit_rate;}
double Skill::get_critical_rate() const{return critical_rate;}
