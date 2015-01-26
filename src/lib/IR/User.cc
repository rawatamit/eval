#include "IR/User.h" 

User::User(Type* type, ValueTy vtype, std::string const& name) :
    Value(type, vtype, name)
{
}

User::~User() {
}
