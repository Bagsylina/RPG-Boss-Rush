#include "../Headers/Skill.h"
#include "../Headers/Player.h"

Skill::Skill(const std::string &sname, const int stype, const int sbase_damage, const int sMP_cost,
             const double shit_rate, const double scritical_rate) : Item(sname), type(stype), base_damage(sbase_damage), MP_cost(sMP_cost), hit_rate(shit_rate), critical_rate(scritical_rate){
    if(type < 0 || type >= (int)(Types.size()))
        throw InvalidType("skill");
    if(base_damage <= 0 || MP_cost < 0 || hit_rate <= 0 || hit_rate > 1 || critical_rate < 0 || critical_rate > 1)
        throw InvalidStats("skill");
}

Item *Skill::clone() const {return new Skill(*this);}

Skill::Skill(const Skill &other) : Item(other.name), type(other.type), base_damage(other.base_damage), MP_cost(other.MP_cost), hit_rate(other.hit_rate), critical_rate(other.critical_rate){}

//citire si afisare
std::istream& operator>>(std::istream& in, Skill& s)
{
    in >> s.name >> s.type >> s.base_damage >> s.MP_cost >> s.hit_rate >> s.critical_rate;
    return in;
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
    where << name << '\n' << "Deals " << base_damage << ' ' << Skill::Types[type] << " damage. Costs " << MP_cost << " MP. Has a hit rate of " << hit_rate*100 << "% and critical rate of " << critical_rate*100 << '%';
}

//geterts
int Skill::get_type() const{return type;}
int Skill::get_damage() const{return base_damage;}
int Skill::get_MP_cost() const{return MP_cost;}
double Skill::get_hit_rate() const{return hit_rate;}
double Skill::get_critical_rate() const{return critical_rate;}

void Skill::useThis(Player& p){
    if(p.get_nr_skills() == 4) { //player needs to discard a skill if it has 4 already equipped
        std::cout << "Choose a skill to forget:\n";
        p.printSkills(std::cout);
        int action = 0;
        std::cin >> action;
        try {
            if (action < 0 || action >= p.get_nr_skills())
                throw InvalidInput();
            Skill s1 = p.get_skill(action - 1);
            p.newItem(s1);
            p.forgetSkill(action - 1);
        }
        catch (InvalidInput &e) {
            std::cout << e.what();
            p.newItem(*this);
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }
    }
    p.learnSkill(*this);
}
