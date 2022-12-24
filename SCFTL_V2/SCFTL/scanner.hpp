#ifndef SCANNER_HPP
#define SCANNER_HPP
#include "headers.hpp"

struct Token{
    string Type;
    string Value;
};

vector<Token> getTokenList(string input);
Token getToken(string Code);
#endif // SCANNER_HPP
