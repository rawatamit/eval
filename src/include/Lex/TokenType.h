#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

enum TokenType {
    T_ADDOP, T_SUBOP,
    T_MULOP, T_DIVOP,
    T_NUMBER,
    T_LPAREN, T_RPAREN,
    T_EOF, T_ERR,
};

#endif
