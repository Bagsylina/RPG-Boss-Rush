#ifndef OOP_ARMOURUPGRADE_H
#define OOP_ARMOURUPGRADE_H

#include "Item.h"

class ArmourUpgrade: public Item{
    int upg_strength, upg_dexterity, upg_vitality, upg_agility, upg_luck;

public:
    explicit ArmourUpgrade(const std::string& aname = "Basic Upgrade", const int astr = 0, const int adex = 0, const int avit = 0, const int aagi = 0, const int alck = 0): Item(aname), upg_strength(astr), upg_dexterity(adex), upg_vitality(avit), upg_agility(aagi), upg_luck(alck)
    {
        if(upg_strength < 0 || upg_dexterity < 0 || upg_vitality < 0 || upg_agility < 0 || upg_luck < 0)
            throw InvalidStats("armour upgrade");
    }
    [[nodiscard]]Item* clone() const override {return new ArmourUpgrade(*this);}

    friend std::istream& operator>>(std::istream&, ArmourUpgrade&);

    void useThis(Player&) override;

private:
    void print(std::ostream&) const override;
};


#endif //OOP_ARMOURUPGRADE_H
