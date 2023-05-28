#ifndef OOP_ARMOURUPGRADE_H
#define OOP_ARMOURUPGRADE_H

#include "Item.h"

class ArmourUpgrade: public Item{
    int upg_strength, upg_dexterity, upg_vitality, upg_agility, upg_luck;

public:
    explicit ArmourUpgrade(const std::string& aname = "Basic Upgrade", int astr = 0, int adex = 0, int avit = 0, int aagi = 0, int alck = 0);
    [[nodiscard]]Item* clone() const override;

    friend std::istream& operator>>(std::istream&, ArmourUpgrade&);

    void useThis(Player&) override;

private:
    void print(std::ostream&) const override;
};


#endif //OOP_ARMOURUPGRADE_H
