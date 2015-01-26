#ifndef USER_H
#define USER_H

#include "IR/Value.h"
#include <string>

class User : public Value {
protected:
    User(Type* type, ValueTy vtype, std::string const& name = "");

public:
    virtual ~User();
};

#endif
