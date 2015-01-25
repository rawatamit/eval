#include "IR/Constants.h"

ConstantInt::ConstantInt(IntegerType *type, int val) :
    Constant(type, Value::ConstantIntV), val_(val) {
}

ConstantInt::~ConstantInt() {
}

ConstantInt* ConstantInt::get(IntegerType *type, int val) {
    return new ConstantInt(type, val);
}

int ConstantInt::getValue() const {
    return val_;
}
