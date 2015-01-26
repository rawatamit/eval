#ifndef BASICBLOCK_H
#define BASICBLOCK_H

#include "IR/Value.h"
#include <list>
#include <string>

class BasicBlock : public Value {
public:
    typedef std::list<Instruction> InstListType;
    typedef InstListType::iterator iterator;
    typedef InstListType::const_iterator const_iterator;
    typedef InstListType::reverse_iterator reverse_iterator;
    typedef InstListType::const_reverse_iterator const_reverse_iterator;

private:
    std::string name_;
    InstListType instlist_;

    BasicBlock(std::string const& name);
    BasicBlock(const BasicBlock &) = delete;
    void operator=(const BasicBlock &) = delete;

public:
    virtual ~BasicBlock();
    static BasicBlock* create(std::string const& name);
};

#endif
