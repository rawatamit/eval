#include "CodeGen/IRGen.h"
#include "IR/BasicBlock.h"
#include "IR/Type.h"
#include "IR/Constants.h"
#include "IR/Instruction.h"
#include "Support/Utils.h"
#include <cstdlib>

IRGen::IRGen(AST* ast) {
    bb_ = BasicBlock::create(basicBlockLabel());
    ast->irgen(this);
}

IRGen::~IRGen() {
}

BasicBlock* IRGen::getIR() {
    return bb_;
}

BasicBlock const* IRGen::getIR() const {
    return bb_;
}

Value* IRGen::visit(AST*) {
    return nullptr;
}

Value* IRGen::visit(Expression*) {
    return nullptr;
}

Value* IRGen::visit(IntegerLiteral* il) {
    return ConstantInt::get(Type::getInt64Ty(),
                            atoi(il->getValue()->getText().c_str()),
                            il->getValue()->getText());
}

Value* IRGen::visit(BinaryExpression*) {
    return nullptr;
}

Value* IRGen::visit(AddExpression* ae) {
    Value* lcode = ae->getLHS()->irgen(this);
    Value* rcode = ae->getRHS()->irgen(this);
    bb_->insertAtBack(AddInst::create(lcode, rcode,
                                     Type::getInt64Ty(),
                                     localVariableName()));
    return bb_->getLastInstruction();
}

Value* IRGen::visit(SubExpression* se) {
    Value* lcode = se->getLHS()->irgen(this);
    Value* rcode = se->getRHS()->irgen(this);
    bb_->insertAtBack(SubInst::create(lcode, rcode,
                                     Type::getInt64Ty(),
                                     localVariableName()));
    return bb_->getLastInstruction();
}

Value* IRGen::visit(MulExpression* me) {
    Value* lcode = me->getLHS()->irgen(this);
    Value* rcode = me->getRHS()->irgen(this);
    bb_->insertAtBack(MulInst::create(lcode, rcode,
                                     Type::getInt64Ty(),
                                     localVariableName()));
    return bb_->getLastInstruction();
    return nullptr;
}

Value* IRGen::visit(DivExpression* de) {
    Value* lcode = de->getLHS()->irgen(this);
    Value* rcode = de->getRHS()->irgen(this);
    bb_->insertAtBack(DivInst::create(lcode, rcode,
                                     Type::getInt64Ty(),
                                     localVariableName()));
    return bb_->getLastInstruction();
}
