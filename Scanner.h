#ifndef SCANNER
#define SCANNER

#include "headers.h"

struct Token{
    string Type;
    string Value;
};

Token getToken(string Code);
std::vector<Token> getTokenList(string input);

#endif //SCANNER
