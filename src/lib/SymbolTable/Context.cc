#include "SymbolTable/Context.h"

Context::Context() :
    enclosingContext_(nullptr)
{
}

Context::~Context() {
}

Context const* Context::getEnclosingContext() const {
    return enclosingContext_;
}
