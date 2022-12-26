#ifndef SCANNER_HPP
#define SCANNER_HPP
#include "headers.hpp"

struct Token{
    std::string Type;
    std::string Value;
};

std::vector<Token> getTokenList(std::string input);
Token getToken(std:: string Code);
#endif // SCANNER_HPP
