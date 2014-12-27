#include "Lex/Lexer.h"
#include "Parse/Parser.h"
#include "IR/AST.h"
#include "CodeGen/ICodeGen.h"
#include "Support/PrintAST.h"
#include "Support/PrintICode.h"
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
    PrintAST pv(progast, std::cout);
    pv.print();
}

void testICode(AST* progast) {
    ICodeGen icgen(progast);
    icgen.translate();
    PrintICode picode(icgen.getICode(), std::cout);
    picode.print();
}

int main(int argc, char* argv[]) {
    Lexer lex(std::cin, "<stdin>");
    //testLexer(lex);
    Parser parser(lex);
    //testParser(parser);
    AST* progast = parser.parse();
    testICode(progast);
    return 0;
}
