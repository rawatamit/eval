#include "Support/ASTBaseVisitor.h"

ASTBaseVisitor::ASTBaseVisitor() {
}

ASTBaseVisitor::~ASTBaseVisitor() {
}

void ASTBaseVisitor::visit(AST*) {
}

void ASTBaseVisitor::visit(Expression*) {
}

void ASTBaseVisitor::visit(IntegerLiteral*) {
}

void ASTBaseVisitor::visit(BinaryExpression*) {
}

void ASTBaseVisitor::visit(AddExpression*) {
}

void ASTBaseVisitor::visit(SubExpression*) {
}

void ASTBaseVisitor::visit(MulExpression*) {
}

void ASTBaseVisitor::visit(DivExpression*) {
}
