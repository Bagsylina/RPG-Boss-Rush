#ifndef OOP_ITEM_H
#define OOP_ITEM_H
#include <string>
#include <iostream>
#include <vector>

class Item{
protected:
    std::string name;
    static const std::vector <std::string> Types;
public:
    Item(const std::string& _name = ""): name(_name){}
    virtual Item* clone() const = 0;

    friend std::ostream& operator<<(std::ostream&, const Item&);

    virtual void print(std::ostream&) const;

    virtual int itemType() const;
    std::string get_name() const;
};


#endif //OOP_ITEM_H
