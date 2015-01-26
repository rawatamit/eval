#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "IR/User.h"

class Instruction : public User {
private:
    BasicBlock* parent_;

    void operator=(Instruction const&) = delete;
    Instruction(Instruction const&) = delete;

public:
    virtual ~Instruction();
    BasicBlock const* getParent() const;
    unsigned getOpcode() const;
    bool isBinaryOp() const;

};

#endif
