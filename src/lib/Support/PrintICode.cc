#include "Support/PrintICode.h"
#include "Support/Utils.h"

PrintICode::PrintICode(std::vector<ICode*>& icode,
                       std::ostream& out) :
    icode_(icode), out_(out) {
}

PrintICode::~PrintICode() {
}

void PrintICode::print() {
    for (auto* code : icode_) {
        code->accept(this);
    }
}

void PrintICode::visit(Const* ct) {
    out_ << ct->getValue();
}

void PrintICode::visit(Temp* tmp) {
    out_ << tmp->getName();
}

void PrintICode::visit(BinOp* bo) {
    out_ << binaryOperatorToString(bo->getOperator()) << ' ';
    bo->getLHS()->accept(this);
    out_ << ' ';
    bo->getRHS()->accept(this);
    out_ << '\n';
}
