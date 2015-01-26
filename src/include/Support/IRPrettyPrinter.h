#ifndef IR_PRETTY_PRINTER_H
#define IR_PRETTY_PRINTER_H

#include <string>
#include <ostream>

class Type;
class Value;
class BasicBlock;
class Instruction;

class IRPrettyPrinter {
private:
    BasicBlock const* bb_;
    std::ostream& out_;
    
    void printValue(Value const* v);
    void printBasicBlock(BasicBlock const* bb);
    void printInstruction(Instruction const* inst);
    std::string typeToString(Type const* type);

public:
    IRPrettyPrinter(BasicBlock const* bb, std::ostream& out);
    virtual ~IRPrettyPrinter();
    void prettyPrint();
};

#endif
