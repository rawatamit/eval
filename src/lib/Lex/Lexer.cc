#include "Lex/Lexer.h"

Lexer::Lexer(std::istream& in, std::string const& filename) :
    ch_(' '), line_(1), column_(0), in_(in), filename_(filename) {
}

Lexer::~Lexer() {
}

std::string const& Lexer::getFilename() const {
    return filename_;
}

int Lexer::readChar() {
    ch_ = in_.get();

    if (ch_ == '\n') {
        ++line_;
        column_ = 0;
    } else {
        ++column_;
    }

    return ch_;
}

Token* Lexer::readNumber() {
    int line = line_, scol = column_;
    std::string text;
    do {
        text.push_back(ch_);
        readChar();
    } while (isdigit(ch_));
    return new Token(line, scol, text.size(), text, T_NUMBER);
}

Token* Lexer::nextToken() {
    // skip whitespace
    while (isspace(ch_))
        readChar();

    // single char tokens
    int line, column;
    switch (ch_) {
    case '+':
        line = line_, column = column_;
        readChar();
        return new Token(line, column, 1, "+", T_ADDOP);
    case '-':
        line = line_, column = column_;
        readChar();
        return new Token(line, column, 1, "-", T_SUBOP);
    case '/':
        line = line_, column = column_;
        readChar();
        return new Token(line, column, 1, "/", T_DIVOP);
    case '*':
        line = line_, column = column_;
        readChar();
        return new Token(line, column, 1, "*", T_MULOP);
    case '(':
        line = line_, column = column_;
        readChar();
        return new Token(line, column, 1, "(", T_LPAREN);
    case ')':
        line = line_, column = column_;
        readChar();
        return new Token(line, column, 1, ")", T_RPAREN);
    default:
        break;
    }

    // number
    if (isdigit(ch_))
        return readNumber();

    // end of file
    if (ch_ == EOF)
        return new Token(line_, column_, 0, "<<EOF>>", T_EOF);

    // error token
    return new Token(line_, column_, 0, "<<ERROR>>", T_ERR);
}
