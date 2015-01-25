#ifndef CONSTANT_H
#define CONSTANT_H

#include "IR/User.h"

class Constant : public User {
protected:
    Constant(Type* type, ValueTy vtype);

public:
    virtual ~Constant();
};

#endif
