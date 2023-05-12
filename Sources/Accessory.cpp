#include "../Headers/Accessory.h"

int Accessory::get_type() const{return type_buff;}
double Accessory::get_buff() const{return buff_percentage;}

std::istream& operator>>(std::istream& in, Accessory& a)
{
    in >> a.name >> a.type_buff >> a.buff_percentage;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Accessory& a)
{
    a.print(out);
    return out;
}

void Accessory::print(std::ostream& where) const {
    where << name << '\n' << Types[type_buff] << " buffed by " << 100 * buff_percentage << '%';
}

int Accessory::itemType() const {return 2;}