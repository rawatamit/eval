#ifndef AST_VISITOR_H
#define AST_VISITOR_H

#include "IR/AST.h"

class ASTVisitor {
public:
    virtual void visit(AST*) = 0;
    virtual void visit(Expression*) = 0;
    virtual void visit(IntegerLiteral*) = 0;
    virtual void visit(BinaryExpression*) = 0;
    virtual void visit(AddExpression*) = 0;
    virtual void visit(SubExpression*) = 0;
    virtual void visit(MulExpression*) = 0;
    virtual void visit(DivExpression*) = 0;
};

#endif
