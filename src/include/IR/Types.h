#ifndef TYPES_H
#define TYPES_H

#include "IR/Type.h"

class IntegerType : public Type {
private:
    static IntegerType* i64type_;
    IntegerType();
    IntegerType(IntegerType&) = delete;

public:
    virtual ~IntegerType();
    static IntegerType* get(unsigned bits);
    unsigned getBitWidth() const;
};

#endif
