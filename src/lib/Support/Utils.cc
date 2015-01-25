#include "Support/Utils.h"

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
