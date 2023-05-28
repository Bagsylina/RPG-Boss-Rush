#include "../Headers/Item.h"

Item::Item(std::string iname) : name{std::move(iname)} {}

const std::vector <std::string> Item::Types = {"Physical", "Pierce", "Projectile", "Fire", "Water", "Electricity", "Earth", "Wind"};

std::ostream& operator<<(std::ostream& out, const Item& i)
{
    i.print(out);
    return out;
}

void Item::print(std::ostream &where) const {
    where << name;
}
