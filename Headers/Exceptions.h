#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H

#include <exception>

class NoItems: public std::exception{
public:
    const char * what () const throw (){return "No items in inventory.\n";}
};

class NoSkills: public std::exception{
public:
    const char * what () const throw (){return "No skills equipped.\n";}
};

class InvalidInput: public std::exception{
public:
    const char * what () const throw (){return "Invalid input.\n";}
};

class NoMoney: public std::exception{
public:
    const char * what () const throw (){return "Not enough money.\n";}
};

class NoLevel: public std::exception{
public:
    const char * what () const throw (){return "Level too low.\n";}
};

#endif //OOP_EXCEPTIONS_H
