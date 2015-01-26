#include "Lex/Lexer.h"
#include "Parse/Parser.h"
#include "IR/AST.h"
#include "Support/PrintAST.h"
#include "CodeGen/IRGen.h"
#include "Support/IRPrettyPrinter.h"
#include <iostream>

void testLexer(Lexer& lex) {
    Token* token = nullptr;
    do {
        token = lex.nextToken();
        std::cout << "line: "   << token->getLine()   << ", "
                  << "column: " << token->getColumn() << ", "
                  << "length: " << token->getLength() << ": "
                  << token->getText() << '\n';
    } while (token->getType() != T_EOF);
}

void testParser(Parser& parser) {
    AST* progast = parser.parse();
    if (progast != nullptr) {
        PrintAST pv(progast, std::cout);
        pv.print();
    }
}

void testIRGen(Parser& parser) {
    AST* progast = parser.parse();
    if (progast != nullptr) {
        IRGen igen(progast);
        IRPrettyPrinter irpp(igen.getIR(), std::cout);
        irpp.prettyPrint();
    }
}

int main(int argc, char* argv[]) {
    Lexer lex(std::cin, "<stdin>");
    Parser parser(lex);
    testIRGen(parser);
    return 0;
}
