#include "SymbolTable/BaseContext.h"

BaseContext::BaseContext() {
}

BaseContext::BaseContext(Context* enclosingContext) :
    Context(enclosingContext)
{
}

BaseContext::~BaseContext() {
    symtab_.clear();
}

void BaseContext::define(std::string& name, Symbol const* sym) {
    symtab_[name] = sym;
}

Symbol const* BaseContext::resolve(std::string& name) const {
    auto const it = symtab_.find(name);
    if (it != symtab_.end()) {
        return it.second;
    } else if (getEnclosingContext() != nullptr) {
        return getEnclosingContext().resolve(name);
    } else {
        return nullptr;
    }
}
