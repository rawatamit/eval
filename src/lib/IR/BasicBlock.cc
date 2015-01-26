#include "IR/BasicBlock.h"

BasicBlock::BasicBlock(std::string const& name) :
    name_(name) {
}

BasicBlock::~BasicBlock() {
}

BasicBlock* BasicBlock::create(std::string const& name) {
    return new BasicBlock(name);
}
