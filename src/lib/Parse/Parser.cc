#include "Parse/Parser.h"
#include "Support/Utils.h"
#include <iostream>

Parser::Parser(Lexer& lex) :
    lex_(lex) {
    consume(); // prime the lexer
}

Parser::~Parser() {
}

// move to the next token in the input stream
void Parser::consume() {
    curtok_ = lex_.nextToken();
}

// check if the expected type and the current token match
// if they don't print an error message, and move onto the next token
void Parser::match(TokenType type) {
    if (type != curtok_->getType()) {
        std::cerr << lex_.getFilename() << ":" << curtok_->getLine()
                  << ":" << curtok_->getColumn() << ": "
                  << "expected '" << tokenTypeToString(type) << "'"
                  << ", got '" << tokenTypeToString(curtok_->getType())
                  << "'\n";
    }

    // eat the current token
    consume();
}

int Parser::getTokenPrecedence(Token* tok) {
    switch (tok->getType()) {
    case T_ADDOP: return 50;
    case T_SUBOP: return 50;
    case T_MULOP: return 100;
    case T_DIVOP: return 100;
    default: return -1;
    }

    return -1;
}

AST* Parser::parse() {
    return expr();
}

// expr -> primary binoprhs
Expression* Parser::expr() {
    Expression* e = primary();
    return e == nullptr ? nullptr : binoprhs(0, e);
}

// binoprhs -> (op primary) *
Expression* Parser::binoprhs(int prec, Expression* lhs) {
    while (true) {
        int ctokprec = getTokenPrecedence(curtok_);

        // lesser precedence than the current operator
        if (ctokprec < prec) return lhs;

        Token* op = curtok_;
        consume(); // eat the binary operator
        Expression* rhs = primary();
        if (rhs == nullptr) return nullptr; // error parsing RHS

        // figure out the associativity
        int nextprec = getTokenPrecedence(curtok_);
        if (ctokprec < nextprec) {
            rhs = binoprhs(ctokprec + 1, rhs);
            if (rhs == nullptr) return nullptr;
        }

        lhs = BinaryExpression::create(op, lhs, rhs);
    }

    return lhs;
}

// primary -> ( expr ) | NUMBER
Expression* Parser::primary() {
    Expression* fe = nullptr;

    switch (curtok_->getType()) {
    case T_NUMBER:
        fe = new IntegerLiteral(curtok_);
        consume(); // eat the number
        break;
    case T_LPAREN:
        consume(); // eat '('
        fe = expr();
        match(T_RPAREN);
        break;
    default:
        std::cerr << lex_.getFilename() << ":" << curtok_->getLine()
                  << ":" << curtok_->getColumn() << ": "
                  << "unknown token inside expression: '"
                  << tokenTypeToString(curtok_->getType()) << "' \n";
        consume(); // skip this token
        break;
    }

    return fe;
}
