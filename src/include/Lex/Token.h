#ifndef TOKEN_H
#define TOKEN_H

#include "TokenType.h"
#include <string>

class Token {
private:
    int line_;
    int column_;
    int length_;
    std::string text_;
    TokenType type_;

public:
    Token(int line,
          int column,
          int length,
          std::string const& text,
          TokenType type);
    virtual ~Token();
    int getLine() const;
    int getColumn() const;
    int getLength() const;
    std::string const& getText() const;
    TokenType getType() const;
};

#endif
