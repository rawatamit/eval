#include "IR/AST.h"
#include "Support/ASTVisitor.h"

/// AST
AST::~AST() {
}

void AST::accept(ASTVisitor* v) {
    v->visit(this);
}

/// Expression
Expression::Expression() {
}

Expression::~Expression() {
}

void Expression::accept(ASTVisitor* v) {
    v->visit(this);
}

/// IntegerLiteral
IntegerLiteral::IntegerLiteral(Token* value) :
    value_(value) {
}

IntegerLiteral::~IntegerLiteral() {
}

Token* IntegerLiteral::getValue() const {
    return value_;
}

void IntegerLiteral::accept(ASTVisitor* v) {
    v->visit(this);
}

/// BinaryExpression
BinaryExpression::BinaryExpression(Token* op,
                                   Expression* lhs,
                                   Expression* rhs) :
    op_(op), lhs_(lhs), rhs_(rhs) {
}

BinaryExpression::~BinaryExpression() {
}

Expression* BinaryExpression::create(Token* op,
                                     Expression* lhs,
                                     Expression* rhs) {
    switch (op->getType()) {
    case T_ADDOP: return new AddExpression(op, lhs, rhs);
    case T_SUBOP: return new SubExpression(op, lhs, rhs);
    case T_MULOP: return new MulExpression(op, lhs, rhs);
    case T_DIVOP: return new DivExpression(op, lhs, rhs);
    default: return nullptr;
    }
    return nullptr;
}

Token* BinaryExpression::getOperator() const {
    return op_;
}

Expression* BinaryExpression::getLHS() const {
    return lhs_;
}

Expression* BinaryExpression::getRHS() const {
    return rhs_;
}

void BinaryExpression::accept(ASTVisitor* v) {
    v->visit(this);
}

/// AddExpression
AddExpression::AddExpression(Token* op,
                             Expression* lhs,
                             Expression* rhs) :
    BinaryExpression(op, lhs, rhs) {
}

AddExpression::~AddExpression() {
}

void AddExpression::accept(ASTVisitor* v) {
    v->visit(this);
}

/// SubExpression
SubExpression::SubExpression(Token* op,
                             Expression* lhs,
                             Expression* rhs) :
    BinaryExpression(op, lhs, rhs) {
}

SubExpression::~SubExpression() {
}

void SubExpression::accept(ASTVisitor* v) {
    v->visit(this);
}

/// MulExpression
MulExpression::MulExpression(Token* op,
                             Expression* lhs,
                             Expression* rhs) :
    BinaryExpression(op, lhs, rhs) {
}

MulExpression::~MulExpression() {
}

void MulExpression::accept(ASTVisitor* v) {
    v->visit(this);
}

/// DivExpression
DivExpression::DivExpression(Token* op,
                             Expression* lhs,
                             Expression* rhs) :
    BinaryExpression(op, lhs, rhs) {
}

DivExpression::~DivExpression() {
}

void DivExpression::accept(ASTVisitor* v) {
    v->visit(this);
}
