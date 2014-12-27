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

std::string binaryOperatorToString(BinaryOperator bop) {
    switch (bop) {
    case B_ADD: return "add";
    case B_SUB: return "sub";
    case B_MUL: return "mul";
    case B_DIV: return "div";
    case B_AND: return "and";
    case B_OR:  return "or";
    case B_XOR: return "xor";
    case B_LSHIFT:  return "lshl";
    case B_RSHIFT:  return "lshr";
    case B_ARSHIFT: return "ashr";
    default: return "<<unknown>>";
    }
}
