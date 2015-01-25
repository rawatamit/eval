#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "IR/Constant.h"
#include "IR/Types.h"

class ConstantInt : public Constant {
private:
    int val_;

private:
    ConstantInt(IntegerType *type, int val);
    ConstantInt(const ConstantInt &) = delete;
    void operator=(const Constant &) = delete;

public:
    virtual ~ConstantInt();
    static ConstantInt* get(IntegerType *type, int val);
    int getValue() const;
};

#endif
