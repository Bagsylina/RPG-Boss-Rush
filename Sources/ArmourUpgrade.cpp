#include "../Headers/ArmourUpgrade.h"
#include "../Headers/Player.h"

std::istream& operator>>(std::istream& in, ArmourUpgrade& au)
{
    in >> au.name >> au.upg_strength >> au.upg_dexterity >> au.upg_vitality >> au.upg_agility >> au.upg_luck;
    return in;
}

void ArmourUpgrade::useThis(Player& player){
    Armour p_ar = player.getArmour();
    Armour new_armour("Upgraded Armour", p_ar.get_bMP(), p_ar.get_bMP(), p_ar.get_bstr() + upg_strength, p_ar.get_bdex() + upg_dexterity,
                      p_ar.get_bvit() + upg_vitality, p_ar.get_bagi() + upg_agility, p_ar.get_blck() + upg_luck);
    player.equip_armour(new_armour);
}

void ArmourUpgrade::print(std::ostream& where) const {
    where << name << "\nUpgrades armour by";
    if(upg_strength)
        where << ' ' << upg_strength << " strength";
    if(upg_dexterity)
        where << ' ' << upg_dexterity << " dexterity";
    if(upg_vitality)
        where << ' ' << upg_vitality << " vitality";
    if(upg_agility)
        where << ' ' << upg_agility << " agility";
    if(upg_luck)
        where << ' ' << upg_luck << " luck";
    where << '.';
}