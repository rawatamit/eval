#include "Support/Utils.h"
#include <cstdio>

std::string basicBlockLabel() {
    static int tmp = 0;
    static char buf[40];
    sprintf(buf, "%s%d", "bb", tmp++);
    return buf;
}

std::string globalVariableName() {
    static int tmp = 0;
    static char buf[40];
    sprintf(buf, "%s%d", "gtmp", tmp++);
    return buf;
}

std::string localVariableName() {
    static int tmp = 0;
    static char buf[40];
    sprintf(buf, "%s%d", "ltmp", tmp++);
    return buf;
}

std::string tokenTypeToString(TokenType type) {
    switch (type) {
    case T_ADDOP: return "+";
    case T_SUBOP: return "-";
    case T_MULOP: return "*";
    case T_DIVOP: return "/";
    case T_NUMBER: return "number";
    case T_LPAREN: return "(";
    case T_RPAREN: return ")";
    case T_EOF: return "<<EOF>>";
    case T_ERR: return "<<ERROR>>";
    default: return "<<unknown>>";
    }
}
