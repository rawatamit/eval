#include "IR/Constants.h"

ConstantInt::ConstantInt(IntegerType *type, int val,
                         std::string const& name) :
    Constant(type, Value::ConstantIntV, name),
    val_(val)
{
}

ConstantInt::~ConstantInt() {
}

ConstantInt* ConstantInt::get(IntegerType *type, int val,
                              std::string const& name) {
    return new ConstantInt(type, val, name);
}

int ConstantInt::getValue() const {
    return val_;
}
