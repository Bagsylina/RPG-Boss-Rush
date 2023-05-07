//
// Created by Anghel Fabian on 19/04/2023.
//

#ifndef OOP_ITEM_H
#define OOP_ITEM_H
#include <string>
#include <iostream>
#include <vector>

const std::vector <std::string> Types = {"Physical", "Pierce", "Projectile", "Fire", "Water", "Electricity", "Earth", "Wind"};

class Item{
protected:
    std::string name;
public:
    Item(const std::string& _name = ""): name(_name){}

    friend std::ostream& operator<<(std::ostream& out, const Item& i)\
    {
        return out << i.name;
    }

    virtual int itemType(){return 0;}
    std::string get_name() const{return name;}
};


#endif //OOP_ITEM_H
