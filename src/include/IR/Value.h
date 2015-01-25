#ifndef VALUE_H
#define VALUE_H

class Type;

class Value {
public:
    enum ValueTy {
        BasicBlockV,
    };
    
private:
    Type* type_;
    ValueTy vtype_;

protected:
    Value(Type* type, ValueTy vtype);

public:
    virtual ~Value();
    Type* getType() const;
    ValueTy getValueType() const;
};

#endif
