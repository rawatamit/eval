#ifndef ICODE_VISITOR_H
#define ICODE_VISITOR_H

#include "IR/ICode.h"

class ICodeVisitor {
public:
    virtual void visit(ICode*) = 0;
    virtual void visit(Const*) = 0;
    virtual void visit(Temp*) = 0;
    virtual void visit(BinOp*) = 0;
};

#endif
