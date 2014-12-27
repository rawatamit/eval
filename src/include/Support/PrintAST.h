#ifndef PRINT_AST_H
#define PRINT_AST_H

#include "Support/ASTBaseVisitor.h"

class PrintAST : public ASTBaseVisitor {
private:
    AST* ast_;
    std::ostream& out_;
    int indent_;

public:
    PrintAST(AST* ast, std::ostream& out);
    virtual ~PrintAST();
    virtual void print();
    virtual void visit(IntegerLiteral*);
    virtual void visit(AddExpression*);
    virtual void visit(SubExpression*);
    virtual void visit(MulExpression*);
    virtual void visit(DivExpression*);
};

#endif
