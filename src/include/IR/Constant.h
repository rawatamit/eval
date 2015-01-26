#ifndef CONSTANT_H
#define CONSTANT_H

#include "IR/User.h"
#include <string>

class Constant : public User {
protected:
    Constant(Type* type, ValueTy vtype, std::string const& name = "");

public:
    virtual ~Constant();
};

#endif
