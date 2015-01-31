#ifndef SYMBOL_H
#define SYMBOL_H

#include "IR/AST.h"
#include "SymbolTable/Type.h"
#include <string>

///// Symbol can act as a Type
class Symbol {//: public Type {
public:
    enum SymbolKind {
        VariableK = 0,
        FunctionK,
    };

private:
    SymbolKind symkind_; // kind of symbol we are dealing with
    AST const* node_;
    //std::string& name_;
    Type const* type_;

public:
    Symbol(SymbolKind symkind_, AST const* node, Type const* type_);
    virtual ~Symbol();
    virtual AST const* getNode() const;
    virtual Type const* getType() const;
    std::string& getName() const = 0;
    bool isVariable() const;
    bool isFunction() const;
};

class VariableSymbol : public Symbol {
public:
    VariableSymbol(AST const* node, Type const* type_);
    virtual ~VariableSymbol();
    std::string& getName() const;
};

#endif
