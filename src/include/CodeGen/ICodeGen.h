#ifndef ICODE_GEN_H
#define ICODE_GEN_H

#include "IR/AST.h"
#include "IR/ICode.h"
#include "Support/ASTBaseVisitor.h"
#include <vector>

class ICodeGen : public ASTBaseVisitor {
private:
    AST* ast_;
    ICode* tmp_;
    std::vector<ICode*> icode_;

public:
    ICodeGen(AST* ast);
    virtual ~ICodeGen();
    std::vector<ICode*>& getICode();
    virtual void translate();
    virtual void visit(IntegerLiteral* il);
    virtual void visit(AddExpression* ae);
    virtual void visit(SubExpression* se);
    virtual void visit(MulExpression* me);
    virtual void visit(DivExpression* de);
};

#endif
