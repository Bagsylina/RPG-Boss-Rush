#ifndef OOP_ITEM_H
#define OOP_ITEM_H
#include <string>
#include <iostream>
#include <vector>
#include "Exceptions.h"

class Player;

class Item{
protected:
    std::string name;
    static const std::vector <std::string> Types;
public:
    Item(const std::string& iname = ""): name(iname){}
    virtual ~Item() = default;
    virtual Item* clone() const = 0;

    friend std::ostream& operator<<(std::ostream&, const Item&);

    virtual void useThis(Player&) = 0;

private:
    virtual void print(std::ostream&) const;
};


#endif //OOP_ITEM_H
