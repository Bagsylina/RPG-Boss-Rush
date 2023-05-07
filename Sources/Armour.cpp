//
// Created by Anghel Fabian on 19/04/2023.
//

#include "../Headers/Armour.h"

//getters
int Armour::get_bHP() const{return bonus_HP;}
int Armour::get_bMP() const{return bonus_MP;}
int Armour::get_bstr() const{return bonus_strength;}
int Armour::get_bdex() const{return bonus_dexterity;}
int Armour::get_bvit() const{return bonus_vitality;}
int Armour::get_bagi() const{return bonus_agility;}
int Armour::get_blck() const{return bonus_luck;}