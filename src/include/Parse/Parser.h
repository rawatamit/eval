#ifndef PARSER_H
#define PARSER_H

#include "IR/AST.h"
#include "Lex/Lexer.h"

class Parser {
private:
    Lexer& lex_;
    Token* curtok_;

private:
    // move to the next token in the input stream
    void consume();

    // check if the expected type and the current token match
    void match(TokenType type);

    // return the token precedence of a given token
    // useful for parsing binary expressions
    int getTokenPrecedence(Token* tok);

    Expression* expr();
    Expression* binoprhs(int prec, Expression* lhs);
    Expression* primary();

public:
    Parser(Lexer& lex);
    virtual ~Parser();
    AST* parse();
};

#endif
