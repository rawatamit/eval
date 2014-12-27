#include "CodeGen/ICodeGen.h"
#include "IR/IOps.h"
#include <cstdlib>

ICodeGen::ICodeGen(AST* ast) :
    ast_(ast), tmp_(nullptr) {
}

ICodeGen::~ICodeGen() {
}

std::vector<ICode*>& ICodeGen::getICode() {
    return icode_;
}

void ICodeGen::translate() {
    ast_->accept(this);
}

void ICodeGen::visit(IntegerLiteral* il) {
    tmp_ = new Const(atoi(il->getValue()->getText().c_str()));
}

void ICodeGen::visit(AddExpression* ae) {
    ae->getLHS()->accept(this);
    ICode* lhs = tmp_;
    ae->getRHS()->accept(this);
    ICode* rhs = tmp_;
    tmp_ = new BinOp(B_ADD, lhs, rhs);
    icode_.push_back(tmp_);
}

void ICodeGen::visit(SubExpression* se) {
    se->getLHS()->accept(this);
    ICode* lhs = tmp_;
    se->getRHS()->accept(this);
    ICode* rhs = tmp_;
    tmp_ = new BinOp(B_SUB, lhs, rhs);
    icode_.push_back(tmp_);
}

void ICodeGen::visit(MulExpression* me) {
    me->getLHS()->accept(this);
    ICode* lhs = tmp_;
    me->getRHS()->accept(this);
    ICode* rhs = tmp_;
    tmp_ = new BinOp(B_MUL, lhs, rhs);
    icode_.push_back(tmp_);
}

void ICodeGen::visit(DivExpression* de) {
    de->getLHS()->accept(this);
    ICode* lhs = tmp_;
    de->getRHS()->accept(this);
    ICode* rhs = tmp_;
    tmp_ = new BinOp(B_DIV, lhs, rhs);
    icode_.push_back(tmp_);
}
