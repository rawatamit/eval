#ifndef ICODE_H
#define ICODE_H

#include "IOps.h"
#include <string>

class ICodeVisitor;

class ICode {
public:
    virtual ~ICode();
    virtual void accept(ICodeVisitor*);
};

class Const : public ICode {
private:
    int value_;

public:
    Const(int value);
    virtual ~Const();
    int getValue() const;
    virtual void accept(ICodeVisitor*);
};

class Temp : public ICode {
private:
    std::string name_;

public:
    // use this function to create new temporaries
    static Temp* get();

public:
    Temp(std::string const& name);
    virtual ~Temp();
    std::string const& getName() const;
    virtual void accept(ICodeVisitor*);
};

class BinOp : public ICode {
private:
    BinaryOperator op_;
    ICode* lhs_;
    ICode* rhs_;

public:
    BinOp(BinaryOperator op, ICode* lhs, ICode* rhs);
    virtual ~BinOp();
    BinaryOperator getOperator() const;
    ICode* getLHS() const;
    ICode* getRHS() const;
    virtual void accept(ICodeVisitor*);
};

#endif
