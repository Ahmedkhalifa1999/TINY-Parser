#ifndef PARSER_H
#define PARSER_H

#include "SyntaxTree.h"

class Parser
{
private:
    SyntaxTree *outputTree = nullptr;

public:
    Parser();

    //Takes a string of TINY-language code and constructs the parse tree in its private member "outputTree"
    void parseString(QString code);

    const SyntaxTree *getOutputTree() const;
};

#endif // PARSER_H
