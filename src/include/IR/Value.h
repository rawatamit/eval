#ifndef VALUE_H
#define VALUE_H

#include <string>

class Type;

class Value {
public:
    enum ValueTy {
        BasicBlockV,
        ConstantIntV,
        InstructionV,
    };

private:
    Type* type_;
    ValueTy vtype_;
    std::string name_;

protected:
    Value(Type* type, ValueTy vtype);
    Value(Type* type, ValueTy vtype, std::string const& name);
    Value(Value const&) = delete;
    void operator=(Value const&) = delete;

public:
    virtual ~Value();
    Type* getType() const;
    ValueTy getValueType() const;
    std::string const& getName() const;
};

#endif
