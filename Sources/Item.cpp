#include "../Headers/Item.h"

const std::vector <std::string> Item::Types = {"Physical", "Pierce", "Projectile", "Fire", "Water", "Electricity", "Earth", "Wind"};

std::ostream& operator<<(std::ostream& out, const Item& i)
{
    i.print(out);
    return out;
}

void Item::print(std::ostream &where) const {
    where << name;
}

int Item::itemType() const{return 0;}

std::string Item::get_name() const{return name;}