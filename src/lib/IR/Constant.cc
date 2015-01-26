#include "IR/Constant.h"

Constant::Constant(Type* type, ValueTy vtype, std::string const& name) :
    User(type, vtype, name)
{
}

Constant::~Constant() {
}
