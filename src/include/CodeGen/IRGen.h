#ifndef IR_GEN_H
#define IR_GEN_H

#include "IR/AST.h"

class Value;
class BasicBlock;

class IRGen {
private:
    BasicBlock* bb_;

public:
    IRGen(AST* ast);
    virtual ~IRGen();
    BasicBlock* getIR();
    BasicBlock const* getIR() const;
    virtual Value* visit(AST*);
    virtual Value* visit(Expression*);
    virtual Value* visit(IntegerLiteral*);
    virtual Value* visit(BinaryExpression*);
    virtual Value* visit(AddExpression*);
    virtual Value* visit(SubExpression*);
    virtual Value* visit(MulExpression*);
    virtual Value* visit(DivExpression*);
};

#endif
