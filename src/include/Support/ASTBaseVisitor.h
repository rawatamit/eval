#ifndef AST_BASE_VISITOR_H
#define AST_BASE_VISITOR_H

#include "ASTVisitor.h"

class ASTBaseVisitor : public ASTVisitor {
public:
    ASTBaseVisitor();
    virtual ~ASTBaseVisitor();
    virtual void visit(AST*);
    virtual void visit(Expression*);
    virtual void visit(IntegerLiteral*);
    virtual void visit(BinaryExpression*);
    virtual void visit(AddExpression*);
    virtual void visit(SubExpression*);
    virtual void visit(MulExpression*);
    virtual void visit(DivExpression*);
};

#endif
