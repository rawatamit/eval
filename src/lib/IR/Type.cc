#include "IR/Type.h"

// Type
Type* Type::voidtype_ = new Type(VoidTy);
Type* Type::labeltype_ = new Type(LabelTy);

Type::Type(TypeID tid) : typeid_(tid) {
}

Type::~Type() {
}

Type::TypeID Type::getTypeID() const {
    return typeid_;
}

bool Type::isIntegerTy() const {
    return getTypeID() == IntegerTy;
}

bool Type::isLabelTy() const {
    return getTypeID() == LabelTy;
}

bool Type::isPointerTy() const {
    return getTypeID() == PointerTy;
}

Type* Type::getVoidTy() {
    return voidtype_;
}

IntegerType* Type::getInt64Ty() {
    return IntegerType::get(64);
}

Type* Type::getLabelTy() {
    return labeltype_;
}

PointerType* Type::getInt64PtrTy() {
    return PointerType::getInt64PtrTy();
}

// IntegerType
IntegerType* IntegerType::i64type_ = new IntegerType();

IntegerType::IntegerType() :
    Type(Type::IntegerTy) {
}

IntegerType::~IntegerType() {
}

IntegerType* IntegerType::get(unsigned bits) {
    return bits == 64 ? i64type_ : nullptr;
}

unsigned IntegerType::getBitWidth() const {
    return this == i64type_ ? 64 : 0;
}

// PointerType
PointerType* PointerType::i64ptype_ = new PointerType();

PointerType::PointerType() :
    Type(Type::PointerTy)
{
}

PointerType::~PointerType() {
}

PointerType* PointerType::getInt64PtrTy() {
    return i64ptype_;
}
