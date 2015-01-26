#include "IR/BasicBlock.h"

BasicBlock::BasicBlock(std::string const& name) :
    Value(Type::getLabelTy(), Value::BasicBlockV, name) {
}

BasicBlock::~BasicBlock() {
}

BasicBlock* BasicBlock::create(std::string const& name) {
    return new BasicBlock(name);
}

BasicBlock::InstListType& BasicBlock::getInstList() {
    return instlist_;
}

BasicBlock::InstListType const& BasicBlock::getInstList() const {
    return instlist_;
}

Instruction* BasicBlock::getLastInstruction() {
    return getInstList().back();
}

Instruction const* BasicBlock::getLastInstruction() const {
    return getInstList().back();
}

void BasicBlock::insertAtBack(Instruction* inst) {
    getInstList().push_back(inst);
}

BasicBlock::iterator BasicBlock::begin() {
    return getInstList().begin();
}

BasicBlock::iterator BasicBlock::end() {
    return getInstList().end();
}

BasicBlock::const_iterator BasicBlock::begin() const {
    return getInstList().begin();
}

BasicBlock::const_iterator BasicBlock::end() const {
    return getInstList().end();
}

BasicBlock::reverse_iterator BasicBlock::rbegin() {
    return getInstList().rbegin();
}

BasicBlock::reverse_iterator BasicBlock::rend() {
    return getInstList().rend();
}

BasicBlock::const_reverse_iterator BasicBlock::rbegin() const {
    return getInstList().rbegin();
}

BasicBlock::const_reverse_iterator BasicBlock::rend() const {
    return getInstList().rend();
}
