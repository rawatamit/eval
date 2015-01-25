#ifndef TYPE_H
#define TYPE_H

#include "IR/Type.h"

class IntegerType : public Type {
private:
    static IntegerType* itype_;
    IntegerType();

public:
    virtual ~IntegerType();
    static IntegerType* get();
};

#endif
