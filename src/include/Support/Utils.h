#ifndef UTILS_H
#define UTILS_H

#include "Lex/TokenType.h"
#include <string>

std::string basicBlockLabel();
std::string globalVariableName();
std::string localVariableName();
std::string tokenTypeToString(TokenType type);

#endif
