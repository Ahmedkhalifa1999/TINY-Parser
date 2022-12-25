#ifndef PARSER_H
#define PARSER_H

#include "Scanner.hpp"
#include "SyntaxTree.h"
#include <stdio.h>
using namespace std;

class Parser
{
private:
    SyntaxTree *outputTree = nullptr;
    bool error = false;

    SyntaxTree* stmt_sequence (vector<Token> Tokens);
    SyntaxTree* statement (vector<Token> Tokens);
    SyntaxTree* if_stmt (vector<Token> Tokens);
    SyntaxTree* repeat_stmt (vector<Token> Tokens);
    SyntaxTree* assign_stmt (vector<Token> Tokens);
    SyntaxTree* read_stmt (vector<Token> Tokens);
    SyntaxTree* write_stmt (vector<Token> Tokens);
    SyntaxTree* exp (vector<Token> Tokens);
    SyntaxTree* comparison_op (vector<Token> Tokens);
    SyntaxTree* simple_exp(vector<Token> Tokens);
    SyntaxTree* addop(vector<Token> Tokens);
    SyntaxTree* term(vector<Token> Tokens);
    SyntaxTree* mulop(vector<Token> Tokens);
    SyntaxTree* factor(vector<Token> Tokens);
    void match(QString input, vector<Token> Tokens);

    unsigned int index = 0;
    Token token;

public:
    Parser();
    SyntaxTree* program (vector<Token> Tokens);
    //Takes a string of TINY-language code and constructs the parse tree in its private member "outputTree"
    void parseString(QString code);
    set<int> err;
    const SyntaxTree *getOutputTree() const;
    bool getError() const;
};

#endif // PARSER_H
