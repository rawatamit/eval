#ifndef LEXER_H
#define LEXER_H

#include "Token.h"
#include <istream>

class Lexer {
private:
    int ch_;
    int line_;
    int column_;
    std::istream& in_;
    std::string filename_;

private:
    int readChar();
    Token* readNumber();

public:
    Lexer(std::istream& in, std::string const& filename_);
    virtual ~Lexer();
    std::string const& getFilename() const;

    // return the next token from the input string
    Token* nextToken();
};

#endif
