#ifndef PRINT_ICODE_H
#define PRINT_ICODE_H

#include "IR/AST.h"
#include "Support/ICodeBaseVisitor.h"
#include <vector>
#include <ostream>

class PrintICode : public ICodeBaseVisitor {
private:
    std::vector<ICode*>& icode_;
    std::ostream& out_;

public:
    PrintICode(std::vector<ICode*>& icode_,
               std::ostream& out);
    virtual ~PrintICode();
    virtual void print();
    virtual void visit(Const*);
    virtual void visit(Temp*);
    virtual void visit(BinOp*);
};

#endif
