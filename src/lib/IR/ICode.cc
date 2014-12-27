#include "IR/ICode.h"
#include "Support/ICodeVisitor.h"
#include <cstdio>

/// ICode
ICode::~ICode() {
}

void ICode::accept(ICodeVisitor* v) {
    v->visit(this);
}

/// Constant
Const::Const(int value) :
    value_(value) {
}

Const::~Const() {
}

int Const::getValue() const {
    return value_;
}

void Const::accept(ICodeVisitor* v) {
    v->visit(this);
}

/// Temp
Temp* Temp::get() {
    char buf[64];
    static int temp = 0;
    snprintf(buf, sizeof buf, "t%d", temp++);
    return new Temp(buf);
}

Temp::Temp(std::string const& name) :
    name_(name) {
}

Temp::~Temp() {
}

std::string const& Temp::getName() const {
    return name_;
}

void Temp::accept(ICodeVisitor* v) {
    v->visit(this);
}

/// BinOp
BinOp::BinOp(BinaryOperator op, ICode* lhs, ICode* rhs) :
    op_(op), lhs_(lhs), rhs_(rhs) {
}

BinOp::~BinOp() {
}

BinaryOperator BinOp::getOperator() const {
    return op_;
}

ICode* BinOp::getLHS() const {
    return lhs_;
}

ICode* BinOp::getRHS() const {
    return rhs_;
}

void BinOp::accept(ICodeVisitor* v) {
    v->visit(this);
}
