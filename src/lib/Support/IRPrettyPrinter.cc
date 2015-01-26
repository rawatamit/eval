#include "Support/IRPrettyPrinter.h"
#include "IR/Type.h"
#include "IR/Value.h"
#include "IR/Instruction.h"
#include "IR/BasicBlock.h"
#include "IR/Constants.h"

IRPrettyPrinter::IRPrettyPrinter(BasicBlock const* bb, std::ostream& out) :
    bb_(bb), out_(out)
{
}

IRPrettyPrinter::~IRPrettyPrinter() {
}

void IRPrettyPrinter::prettyPrint() {
    printBasicBlock(bb_);
}

void IRPrettyPrinter::printValue(Value const* v) {
    switch (v->getValueType()) {
    case Value::BasicBlockV:
        printBasicBlock(dynamic_cast<BasicBlock const*>(v));
        break;

    case Value::InstructionV:
        printInstruction(dynamic_cast<Instruction const*>(v));
        break;

    default:
        out_ << "<unknown value>\n";
        break;
    }
}

void IRPrettyPrinter::printBasicBlock(BasicBlock const* bb) {
    out_ << bb->getName() << ":\n";
    for (Value const* v : *bb) {
        printValue(v);
    }
}

void IRPrettyPrinter::printInstruction(Instruction const* inst) {
    if (inst->isBinaryOp()) {
        BinaryOperator const* binst = dynamic_cast<BinaryOperator const*>(inst);
        out_ << "    "
             << binst->getName() << " = "
             << binst->getOpcodeName() << ' '
             << typeToString(binst->getType()) << ' '
             << binst->getLHS()->getName() << ", "
             << binst->getRHS()->getName() << '\n';
    }
}

std::string IRPrettyPrinter::typeToString(Type const* type) {
    if (type == Type::getInt64Ty())
        return "i64";
    return "utype";
}
