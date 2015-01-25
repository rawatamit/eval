#include "IR/Constant.h"

Constant::Constant(Type* type, ValueTy vtype) :
    User(type, vtype) {
}

Constant::~Constant() {
}
