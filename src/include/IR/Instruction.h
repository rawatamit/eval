#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "IR/User.h"
#include <string>

class BasicBlock;

class Instruction : public User {
public:
    enum InstTy {
        // binary operators
        BinaryOpStart = 0,
        Add,
        Sub,
        Mul,
        Div,
        BinaryOpEnd,
        
        Store,
        Load,
    };
    
    typedef InstTy InstOpcode;
    
private:
    BasicBlock* parent_;
    InstTy itype_;

    void operator=(Instruction const&) = delete;
    Instruction(Instruction const&) = delete;

protected:
    Instruction(Type* type, InstTy itype, std::string const& name = "");
    
public:
    virtual ~Instruction();
    BasicBlock const* getParent() const;
    InstOpcode getOpcode() const;
    std::string getOpcodeName() const;
    bool isBinaryOp() const;
};

// BinaryOperator
class BinaryOperator : public Instruction {
private:
    Value* lhs_;
    Value* rhs_;

protected:
    BinaryOperator(Value* lhs,
                   Value* rhs,
                   Type* type,
                   InstTy itype,
                   std::string const& name = "");

public:
    virtual ~BinaryOperator();
    Value* getLHS() const;
    Value* getRHS() const;
};

// AddInst
class AddInst : public BinaryOperator {
private:
    AddInst(Value* lhs, Value* rhs,
            Type* type, std::string const& name = "");
public:
    virtual ~AddInst();
    static AddInst* create(Value* lhs, Value* rhs,
                           Type* type, std::string const& name = "");
};

// SubInst
class SubInst : public BinaryOperator {
private:
    SubInst(Value* lhs, Value* rhs,
            Type* type, std::string const& name = "");
public:
    virtual ~SubInst();
    static SubInst* create(Value* lhs, Value* rhs,
                           Type* type, std::string const& name = "");
};

// MulInst
class MulInst : public BinaryOperator {
private:
    MulInst(Value* lhs, Value* rhs,
            Type* type, std::string const& name = "");
public:
    virtual ~MulInst();
    static MulInst* create(Value* lhs, Value* rhs,
                           Type* type, std::string const& name = "");
};

// DivInst
class DivInst : public BinaryOperator {
private:
    DivInst(Value* lhs, Value* rhs,
            Type* type, std::string const& name = "");
public:
    virtual ~DivInst();
    static DivInst* create(Value* lhs, Value* rhs,
                           Type* type, std::string const& name = "");
};

// StoreInst
class StoreInst : public Instruction {
private:
    Value* val_;
    Value* addr_;
    
    StoreInst(Value* val, Value* addr,
              std::string const& name = "");
public:
    virtual ~StoreInst();
    static StoreInst* create(Value* val, Value* addr,
                             std::string const& name = "");
    Value* getValueOperand() const;
    Value* getPointerOperand() const;
};

// UnaryInstruction
class UnaryInstruction : public Instruction {
private:
    Value* operand_;

protected:
    UnaryInstruction(Value* operand,
                     Type* type,
                     InstTy itype,
                     std::string const& name = "");

public:
    virtual ~UnaryInstruction();
    Value* getOperand() const;
};

// LoadInst
class LoadInst : public UnaryInstruction {
private:
    LoadInst(Value* ptr,
             Type* type,
             std::string const& name = "");

public:
    virtual ~LoadInst();
    static LoadInst* get(Value* ptr,
                         Type* type,
                         std::string const& name = "");
    Value* getPointerOperand() const;
};

#endif
