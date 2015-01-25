#include "IR/Value.h"

Value::Value(Type* type, ValueTy vtype) :
    type_(type), vtype_(vtype) {
}

Value::Value(Type* type, ValueTy vtype, std::string const& name) :
    type_(type), vtype_(vtype), name_(name) {
}

Value::~Value() {
}

Type* Value::getType() const {
    return type_;
}

Value::ValueTy Value::getValueType() const {
    return vtype_;
}

std::string const& Value::getName() const {
    return name_;
}
