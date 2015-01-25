#include "IR/Value.h"

Value::Value(Type* type, ValueTy vtype) : type_(type) {
}

Value::~Value() {
}

Type* Value::getType() const {
    return type_;
}

Value::ValueTy Value::getValueType() const {
    return vtype_;
}
