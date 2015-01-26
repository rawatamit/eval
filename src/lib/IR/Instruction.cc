#include "IR/Instruction.h"
#include "IR/Type.h"

Instruction::Instruction(Type* type, InstTy itype, std::string const& name) :
    User(type, Value::InstructionV, name), itype_(itype)
{
}

Instruction::~Instruction() {
}

BasicBlock const* Instruction::getParent() const {
    return parent_;
}

Instruction::InstOpcode Instruction::getOpcode() const {
    return itype_;
}

std::string Instruction::getOpcodeName() const {
    switch (itype_) {
    case Add: return "add";
    case Sub: return "sub";
    case Mul: return "mul";
    case Div: return "div";
    case Store: return "store";
    default:  return "<unknown>";
    }
}

bool Instruction::isBinaryOp() const {
    return getOpcode() > BinaryOpStart and getOpcode() < BinaryOpEnd;
}

// BinaryOperator
BinaryOperator::BinaryOperator(
        Value* lhs,
        Value* rhs,
        Type* type,
        InstTy itype,
        std::string const& name) :
    Instruction(type, itype, name), lhs_(lhs), rhs_(rhs)
{
}

BinaryOperator::~BinaryOperator() {
}

Value* BinaryOperator::getLHS() const {
    return lhs_;
}

Value* BinaryOperator::getRHS() const {
    return rhs_;
}

// AddInst
AddInst::AddInst(Value* lhs, Value* rhs,
                 Type* type, std::string const& name) :
    BinaryOperator(lhs, rhs, type, Instruction::Add, name)
{
}

AddInst::~AddInst() {
}

AddInst* AddInst::create(Value* lhs, Value* rhs,
                         Type* type, std::string const& name)
{
    return new AddInst(lhs, rhs, type, name);
}

// SubInst
SubInst::SubInst(Value* lhs, Value* rhs,
                 Type* type, std::string const& name) :
    BinaryOperator(lhs, rhs, type, Instruction::Sub, name)
{
}

SubInst::~SubInst() {
}

SubInst* SubInst::create(Value* lhs, Value* rhs,
                         Type* type, std::string const& name)
{
    return new SubInst(lhs, rhs, type, name);
}

// MulInst
MulInst::MulInst(Value* lhs, Value* rhs,
                 Type* type, std::string const& name) :
    BinaryOperator(lhs, rhs, type, Instruction::Mul, name)
{
}

MulInst::~MulInst() {
}

MulInst* MulInst::create(Value* lhs, Value* rhs,
                         Type* type, std::string const& name)
{
    return new MulInst(lhs, rhs, type, name);
}

// DivInst
DivInst::DivInst(Value* lhs, Value* rhs,
                 Type* type, std::string const& name) :
    BinaryOperator(lhs, rhs, type, Instruction::Div, name)
{
}

DivInst::~DivInst() {
}

DivInst* DivInst::create(Value* lhs, Value* rhs,
                         Type* type, std::string const& name)
{
    return new DivInst(lhs, rhs, type, name);
}

// StoreInst
StoreInst::StoreInst(Value* val, Value* addr,
            std::string const& name) :
    Instruction(Type::getVoidTy(), Instruction::Store, name),
    val_(val), addr_(addr)
{
}

StoreInst::~StoreInst() {
}

StoreInst* StoreInst::create(Value* val, Value* addr,
                             std::string const& name)
{
    return new StoreInst(val, addr, name);
}

Value* StoreInst::getValueOperand() const {
    return val_;
}

Value* StoreInst::getPointerOperand() const {
    return addr_;
}

// UnaryInstruction
UnaryInstruction::UnaryInstruction(Value* operand,
                                   Type* type,
                                   InstTy itype,
                                   std::string const& name) :
    Instruction(type, itype, name), operand_(operand)
{
}

UnaryInstruction::~UnaryInstruction() {
}

Value* UnaryInstruction::getOperand() const {
    return operand_;
}

// LoadInst
LoadInst::LoadInst(Value* ptr,
                   Type* type,
                   std::string const& name) :
    UnaryInstruction(ptr, ptr->getType(), Instruction::Load, name)
{
}

LoadInst::~LoadInst() {
}

LoadInst* LoadInst::get(Value* ptr,
                        Type* type,
                        std::string const& name)
{
    return new LoadInst(ptr, type, name);
}

Value* LoadInst::getPointerOperand() const {
    return getOperand();
}
