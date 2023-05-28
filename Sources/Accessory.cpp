#include "../Headers/Accessory.h"
#include "../Headers/Player.h"

Accessory::Accessory(const std::string &aname, const int atype_buff, const double abuff_percentage) : Item(aname), type_buff(atype_buff), buff_percentage(abuff_percentage){
    if(type_buff < 0 || type_buff >= (int)(Types.size()))
        throw InvalidType("accessory");
    if(buff_percentage < 0 || buff_percentage > 1)
        throw InvalidData("accessory");
}

Item *Accessory::clone() const {return new Accessory(*this);}

int Accessory::get_type() const{return type_buff;}
double Accessory::get_buff() const{return buff_percentage;}

std::istream& operator>>(std::istream& in, Accessory& a)
{
    in >> a.name >> a.type_buff >> a.buff_percentage;
    return in;
}

void Accessory::print(std::ostream& where) const {
    where << name << '\n' << Types[type_buff] << " buffed by " << 100 * buff_percentage << '%';
}

void Accessory::useThis(Player& p){
    Accessory a1 = p.getAccessory();
    p.newItem(a1);
    p.equip_accessory(*this);
}
