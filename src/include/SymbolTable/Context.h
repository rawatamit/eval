#ifndef CONTEXT_H
#define CONTEXT_H

#include <string>

typedef std::string Symbol;

class Context {
private:
    Context* enclosingContext_;
public:
    Context();
    virtual ~Context();
    virtual Context const* getEnclosingContext() const;
    virtual void define(std::string& name, Symbol const* sym) = 0;
    virtual Symbol const* resolve(std::string& name) const = 0;
};

#endif
