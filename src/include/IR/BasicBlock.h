#ifndef BASICBLOCK_H
#define BASICBLOCK_H

#include "IR/Value.h"
#include "IR/Instruction.h"
#include <list>
#include <string>

class BasicBlock : public Value {
public:
    typedef std::list<Instruction*> InstListType;
    typedef InstListType::iterator iterator;
    typedef InstListType::const_iterator const_iterator;
    typedef InstListType::reverse_iterator reverse_iterator;
    typedef InstListType::const_reverse_iterator const_reverse_iterator;

private:
    InstListType instlist_;

    BasicBlock(std::string const& name = "");
    BasicBlock(const BasicBlock &) = delete;
    void operator=(const BasicBlock &) = delete;

public:
    virtual ~BasicBlock();
    static BasicBlock* create(std::string const& name);
    InstListType& getInstList();
    InstListType const& getInstList() const;
    Instruction* getLastInstruction();
    Instruction const* getLastInstruction() const;
    void insertAtBack(Instruction* inst);
    
    // iterators
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
};

#endif
