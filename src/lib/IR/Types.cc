#include "IR/Types.h"

IntegerType::IntegerType() :
    Type(Type::IntegerTy) {
}

IntegerType::~IntegerType() {
}

IntegerType* IntegerType::get(unsigned bits) {
    if (i64type_ == nullptr) i64type_ = new IntegerType();
    return bits == 64 ? i64type_ : nullptr;
}

unsigned IntegerType::getBitWidth() const {
    return this == i64type_ ? 64 : 0;
}
