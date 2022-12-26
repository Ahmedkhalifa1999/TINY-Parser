#include "Parser.h"
#include <QString>

void Parser::match(QString input, std::vector<Token> Tokens){
    if(index<Tokens.size())
    {
        if(input.toStdString() == Tokens[index].Type){
            std:: cout<<"Correct:" <<"Type:" <<Tokens[index].Type<<" ,Value:" <<Tokens[index].Value<<std::endl;
            if(index+1<Tokens.size())
            index++;
        }
        else{
            error = true;
            std:: cout<<"InCorrect:" <<"Type:" <<Tokens[index].Type<<" ,Value:" <<Tokens[index].Value<<std::endl;
           err.insert(index);
        }
    }
    else{
        error = true;

       err.insert(index);
    }

}

Parser::Parser()
{
    error=false;
}

void Parser::parseString(QString code)
{
    index=0;
    error=false;
    err.clear();
    outputTree = Parser::program(getTokenList(code.toStdString()));
}

SyntaxTree *Parser::getOutputTree()
{
    return outputTree;
}

SyntaxTree* Parser::program (std::vector<Token> Tokens){

    SyntaxTree* node = stmt_sequence(Tokens);
     if (index < Tokens.size()-1) {
       std:: cout<<"error"<<std::endl;
        error = true;
        err.insert(index);
    }
    return node;
}


SyntaxTree* Parser::stmt_sequence (std::vector<Token> Tokens){
    SyntaxTree *seq = new SyntaxTree();

    seq = statement(Tokens);

    SyntaxTree *current = new SyntaxTree();

    current = seq;

    Token x;
    if(index < Tokens.size()){

        x = Tokens[index];
    }

    while (x.Type == "SEMICOLON" && index != Tokens.size()-1){

        match("SEMICOLON",Tokens);

        current->setSibling(statement(Tokens));

        current = current->getSibling();

        if(index<Tokens.size()){
            x = Tokens[index];

        }
        else
            break;

    }
    return seq;
}

//if -stmt -> if exp then stmt-sequence [else statment] end

SyntaxTree* Parser::if_stmt (std::vector<Token> Tokens){
    SyntaxTree *current = new SyntaxTree();
    current->setType(IF_STATEMENT);
    match("IF",Tokens);
    current->addChild(exp(Tokens));
    match("THEN",Tokens);
    current->addChild(stmt_sequence(Tokens));
    Token x;
    if(index<Tokens.size()){
        x = Tokens[index];
    }
    if(x.Type == "ELSE"){
        match("ELSE",Tokens);
        current->addChild(stmt_sequence(Tokens));
    }
    match("END",Tokens);
    return current;
}

//read -stmt -> read identifier

SyntaxTree* Parser::read_stmt (std::vector<Token> Tokens){
    match("READ",Tokens);
    SyntaxTree *current = new SyntaxTree();
    current->setType(READ_STATEMENT);
    current->setValue(QString::fromStdString(Tokens[index].Value));
    match("IDENTIFIER",Tokens);
    return current;
}

//write -stmt -> write exp

SyntaxTree* Parser::write_stmt (std::vector<Token> Tokens){
    SyntaxTree *current= new SyntaxTree();
    current->setType(WRITE_STATEMENT);
    match("WRITE",Tokens);
    current->addChild(exp(Tokens));
    return current;
}


SyntaxTree* Parser::statement (std::vector<Token> Tokens){
    SyntaxTree* node = NULL;
    Token current_token;
    if(index < Tokens.size())
        current_token = Tokens[index];
    if( current_token.Type == "IF" ){
        node = if_stmt(Tokens);
    } else if(current_token.Type == "IDENTIFIER"){
        node = assign_stmt(Tokens);
    } else if (current_token.Type == "READ")
        node = read_stmt(Tokens);
    else if (current_token.Type == "WRITE")
        node = write_stmt(Tokens);
    else if (current_token.Type == "REPEAT")
        node = repeat_stmt(Tokens);
    else{
        error = true;
        err.insert(index);
    }
    return node;
}

SyntaxTree* Parser::repeat_stmt (std::vector<Token> Tokens){
    SyntaxTree* node = new SyntaxTree();
    match("REPEAT", Tokens);
    node->setType(REPEAT_STATEMENT);
    node->addChild(stmt_sequence(Tokens));
    match("UNTIL", Tokens);
    node->addChild(exp(Tokens));
    return node;
}

SyntaxTree* Parser::assign_stmt (std::vector<Token> Tokens){
    SyntaxTree* node = new SyntaxTree();
    node->setType(ASSIGN_STATEMENT);
    match("IDENTIFIER",Tokens);
    match("ASSIGN", Tokens);
    node->addChild(exp(Tokens));
    return node;
}

SyntaxTree* Parser::exp (std::vector<Token> Tokens){
    SyntaxTree* cur, *c1 = simple_exp(Tokens), *c2;
    Token x;
    if (index < Tokens.size())
        x = Tokens[index];
    if (x.Type == "LESSTHAN" || x.Type == "EQUAL") {
        cur = comparison_op(Tokens);
        cur->addChild(c1);
        c2 = simple_exp(Tokens);
        cur->addChild(c2);
        c1 = cur;
    }
    return c1;
}

//comparison-op -> < | =


SyntaxTree* Parser::comparison_op (std::vector<Token> Tokens){
    Token x;
    if (index < Tokens.size())
        x = Tokens[index];
    SyntaxTree *current = NULL;
    if(x.Type == "LESSTHAN"){
        current = new SyntaxTree();
        current->setType(OPERATOR_EXPRESSION);
        current->setValue(QString::fromStdString(Tokens[index].Value));
        match("LESSTHAN",Tokens);
    }
    else if(x.Type == "EQUAL"){
        current = new SyntaxTree();
        current->setType(OPERATOR_EXPRESSION);
        current->setValue(QString::fromStdString(Tokens[index].Value));
        match("EQUAL",Tokens);
    }
    else{
        error = true;
        err.insert(index);
    }
    return current;
}

//simple-exp -> term {addop term}

SyntaxTree* Parser::simple_exp(std::vector<Token> Tokens){
    SyntaxTree *current, *c1 = term(Tokens), *c2;
    Token x;
    if(index<Tokens.size()){
        x=Tokens[index];
    }
    while (x.Type=="PLUS" || x.Type == "MINUS")
    {
        current = addop(Tokens);
        current->addChild(c1);
        c2 = term(Tokens);
        current->addChild(c2);
        c1 = current;
        if(index<Tokens.size()){
            x=Tokens[index];
        }
        else{
            break;
        }
    }
    return c1;
}

//addop -> + | -

SyntaxTree* Parser::addop(std::vector<Token> Tokens){
    Token x;
    if(index<Tokens.size()){
        x = Tokens[index];
    }
    SyntaxTree *current = NULL;
    if(x.Type == "PLUS"){
        current = new SyntaxTree();
        current->setType(OPERATOR_EXPRESSION);
        current->setValue(QString::fromStdString(Tokens[index].Value));
        match("PLUS",Tokens);
    }
    else if(x.Type == "MINUS"){
        current = new SyntaxTree();
        current->setType(OPERATOR_EXPRESSION);
        current->setValue(QString::fromStdString(Tokens[index].Value));
        match("MINUS",Tokens);
    }
    else{
        error = true;
        err.insert(index);
    }
    return current;
}

//term -> factor {mulop factor}

SyntaxTree* Parser::term(std::vector<Token> Tokens){
    SyntaxTree *current, *c1 = factor(Tokens), *c2;
    Token x;
    if(index<Tokens.size()){
        x=Tokens[index];
    }
    while (x.Type=="MULT" || x.Type == "DIV")
    {
        current = mulop(Tokens);
        current->addChild(c1);
        c2 = factor(Tokens);
        current->addChild(c2);
        c1 = current;
        if(index<Tokens.size()){
            x=Tokens[index];
        }
        else{
            break;
        }
    }
    return c1;
}

//mulop -> * | /

SyntaxTree* Parser::mulop(std::vector<Token> Tokens){
    Token x;
    if(index<Tokens.size()){
        x = Tokens[index];
    }
    SyntaxTree *current = NULL;
    if(x.Type == "MULT"){
        current = new SyntaxTree();
        current->setType(OPERATOR_EXPRESSION);
        current->setValue(QString::fromStdString(Tokens[index].Value));
        match("MULT",Tokens);
    }
    else if(x.Type == "DIV"){
        current = new SyntaxTree();
        current->setType(OPERATOR_EXPRESSION);
        current->setValue(QString::fromStdString(Tokens[index].Value));
        match("DIV",Tokens);
    }
    else{
        error = true;
        err.insert(index);
    }
    return current; 
}

//factor -> (exp) | number | identifier

SyntaxTree* Parser::factor(std::vector<Token> Tokens){
    Token x;
    if(index<Tokens.size()){
        x = Tokens[index];
    }
    SyntaxTree *current = NULL;
    if(x.Type == "OPENBRACKET"){
        match("OPENBRACKET",Tokens);
        current=exp(Tokens);
        match("CLOSEDBRACKET",Tokens);
    }
    else if (x.Type == "NUMBER"){
        current = new SyntaxTree();
        current->setType(CONSTANT_EXPRESSION);
        current->setValue(QString::fromStdString(Tokens[index].Value));
        match("NUMBER",Tokens);
    }
    else if (x.Type == "IDENTIFIER"){
        current = new SyntaxTree();
        current->setType(IDENTIFIER_EXPRESSION);
        current->setValue(QString::fromStdString(Tokens[index].Value));
        match("IDENTIFIER",Tokens);
    }
    else{
        error = true;
        err.insert(index);
    }
    return current;
}

bool Parser::getError() const
{
    std::cout<<error<<std::endl;
    return error;
}
