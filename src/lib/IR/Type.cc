#include "IR/Type.h"

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
