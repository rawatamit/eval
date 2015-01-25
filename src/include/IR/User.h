#ifndef USER_H
#define USER_H

#include "IR/Value.h"

class User : public Value {
private:
    User(Type* type, ValueTy vtype);

public:
    virtual ~User();
};

#endif
