#include "Support/ICodeBaseVisitor.h"

ICodeBaseVisitor::ICodeBaseVisitor() {
}

ICodeBaseVisitor::~ICodeBaseVisitor() {
}

void ICodeBaseVisitor::visit(ICode*) {
}

void ICodeBaseVisitor::visit(Const*) {
}

void ICodeBaseVisitor::visit(Temp*) {
}

void ICodeBaseVisitor::visit(BinOp*) {
}
