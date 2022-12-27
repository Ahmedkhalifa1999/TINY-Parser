#ifndef SCANNER_HPP
#define SCANNER_HPP
#include "headers.hpp"
extern bool ErrorScanner;
struct Token{
    std::string Type;
    std::string Value;
};

std::vector<Token> getTokenList(std::string input);
Token getToken(std:: string Code);
#endif // SCANNER_HPP
