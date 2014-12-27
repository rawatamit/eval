#ifndef ICODE_BASE_VISITOR_H
#define ICODE_BASE_VISITOR_H

#include "ICodeVisitor.h"

class ICodeBaseVisitor : public ICodeVisitor {
public:
    ICodeBaseVisitor();
    virtual ~ICodeBaseVisitor();
    virtual void visit(ICode*);
    virtual void visit(Const*);
    virtual void visit(Temp*);
    virtual void visit(BinOp*);
};

#endif
