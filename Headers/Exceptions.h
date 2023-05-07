#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H

#include <exception>

using namespace std;

class NoItems: public exception{
public:
    const char * what () const throw (){return "No items in inventory.\n";}
};

class NoSkills: public exception{
public:
    const char * what () const throw (){return "No skills equipped.\n";}
};

class InvalidInput: public exception{
public:
    const char * what () const throw (){return "Invalid input.\n";}
};

class NoMoney: public exception{
public:
    const char * what () const throw (){return "Not enough money\n";}
};

class NoLevel: public exception{
public:
    const char * what () const throw (){return "Level too low\n";}
};

#endif //OOP_EXCEPTIONS_H
