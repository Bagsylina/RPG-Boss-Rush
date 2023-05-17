#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H

#include <exception>
#include <string>

class GameError: public std::runtime_error{
    using std::runtime_error::runtime_error;
};

class NoThings: public GameError {
public:
    explicit NoThings(const std::string& err): GameError(err) {}
};

class NoItems: public NoThings {
public:
    explicit NoItems(const std::string& location): NoThings("No items in " + location + ".\n") {}
};

class NoSkills: public NoThings {
public:
    explicit NoSkills(): NoThings("No skills equipped.\n") {}
};

class NoMoney: public NoThings {
public:
    explicit NoMoney(): NoThings("Not enough money.\n") {}
};

class NoLevel: public NoThings {
public:
    explicit NoLevel(): NoThings("Level too low.\n") {}
};

class NoMP: public NoThings {
public:
    explicit NoMP(): NoThings("Not enough MP.\n") {}
};

class InvalidInput: public GameError{
public:
    explicit InvalidInput(): GameError("Invalid input.\n") {}
};

class InvalidData: public GameError{
public:
    explicit InvalidData(const std::string& err): GameError(err) {}
};

class InvalidType: public InvalidData{
public:
    explicit InvalidType(const std::string& err): InvalidData("Invalid" + err + "type.\n") {}
};

class InvalidStats: public InvalidData{
public:
    explicit InvalidStats(const std::string& err): InvalidData("Invalid " + err + " stats.\n") {}
};

class InvalidHeal: public InvalidData{
public:
    explicit InvalidHeal(): InvalidData("Invalid healing stats.\n") {}
};

#endif //OOP_EXCEPTIONS_H
