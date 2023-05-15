#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H

#include <exception>

class NoThings: public std::exception{
public:
    const char * what () const throw (){return "Not enough things.\n";};
};

class NoItems: public NoThings{
public:
    const char * what () const throw (){return "No items in inventory.\n";}
};

class NoSkills: public NoThings{
public:
    const char * what () const throw (){return "No skills equipped.\n";}
};

class NoMoney: public NoThings{
public:
    const char * what () const throw (){return "Not enough money.\n";}
};

class NoLevel: public NoThings{
public:
    const char * what () const throw (){return "Level too low.\n";}
};

class NoMP: public NoThings{
public:
    const char * what () const throw (){return "MP too low.\n";}
};

class InvalidInput: public std::exception{
public:
    const char * what () const throw (){return "Invalid input.\n";}
};

class InvalidData: public std::exception{
public:
    const char * what () const throw(){return "Invalid data.\n";}
};

class InvalidType: public InvalidData{
    const char * what () const throw(){return "Invalid type.\n";}
};

#endif //OOP_EXCEPTIONS_H
