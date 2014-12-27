#ifndef AST_H
#define AST_H

#include "Lex/Token.h"
#include <ostream>

class ASTVisitor;

class AST {
public:
    virtual ~AST();
    virtual void accept(ASTVisitor* v);
};

class Expression : public AST {
public:
    Expression();
    virtual ~Expression();
    virtual void accept(ASTVisitor* v);
};

class IntegerLiteral : public Expression {
private:
    Token* value_;

public:
    IntegerLiteral(Token* value);
    virtual ~IntegerLiteral();
    Token* getValue() const;
    virtual void accept(ASTVisitor* v);
};

class BinaryExpression : public Expression {
private:
    Token* op_;
    Expression* lhs_;
    Expression* rhs_;

public:
    // factory method to create binary expressions
    // depending on their type, should be used
    static Expression* create(Token* op,
                              Expression* lhs,
                              Expression* rhs);

public:
    BinaryExpression(Token* op,
                     Expression* lhs,
                     Expression* rhs);
    virtual ~BinaryExpression();
    Token* getOperator() const;
    Expression* getLHS() const;
    Expression* getRHS() const;
    virtual void accept(ASTVisitor* v);
};

class AddExpression : public BinaryExpression {
public:
    AddExpression(Token* op,
                  Expression* lhs,
                  Expression* rhs);
    virtual ~AddExpression();
    virtual void accept(ASTVisitor* v);
};

class SubExpression : public BinaryExpression {
public:
    SubExpression(Token* op,
                  Expression* lhs,
                  Expression* rhs);
    virtual ~SubExpression();
    virtual void accept(ASTVisitor* v);
};

class MulExpression : public BinaryExpression {
public:
    MulExpression(Token* op,
                  Expression* lhs,
                  Expression* rhs);
    virtual ~MulExpression();
    virtual void accept(ASTVisitor* v);
};

class DivExpression : public BinaryExpression {
public:
    DivExpression(Token* op,
                  Expression* lhs,
                  Expression* rhs);
    virtual ~DivExpression();
    virtual void accept(ASTVisitor* v);
};

#endif
