#ifndef BASE_CONTEXT_H
#define BASE_CONTEXT_H

#include "SymbolTable/Context.h"
#include <map>

class BaseContext : public Context {
private:
    std::map<std::string, Symbol const*> symtab_;
public:
    BaseContext();
    BaseContext(Context* enclosingContext);
    virtual ~BaseContext();
    virtual void define(std::string& name, Symbol const* sym);
    virtual Symbol const* resolve(std::string& name) const;
};

#endif
