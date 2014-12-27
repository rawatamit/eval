#ifndef UTILS_H
#define UTILS_H

#include "Lex/TokenType.h"
#include "IR/ICode.h"
#include <string>

std::string tokenTypeToString(TokenType type);
std::string binaryOperatorToString(BinaryOperator bop);

#endif
