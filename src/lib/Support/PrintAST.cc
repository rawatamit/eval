#include "Support/PrintAST.h"

PrintAST::PrintAST(AST* ast, std::ostream& out) :
    ast_(ast), out_(out), indent_(0) {
}

PrintAST::~PrintAST() {
}

void PrintAST::print() {
    ast_->accept(this);
    out_ << '\n';
}

void PrintAST::visit(IntegerLiteral* il) {
    out_ << std::string(indent_, ' ')
         << "<integer>: " << il->getValue()->getText();
}

void PrintAST::visit(AddExpression* ae) {
    out_ << std::string(indent_, ' ')
         << "<addexpr>: " << ae->getOperator()->getText() << '\n';
    indent_ += 4;
    ae->getLHS()->accept(this); out_ << '\n';
    ae->getRHS()->accept(this);
    indent_ -= 4;
}

void PrintAST::visit(SubExpression* se) {
    out_ << std::string(indent_, ' ')
         << "<subexpr>: " << se->getOperator()->getText() << '\n';
    indent_ += 4;
    se->getLHS()->accept(this); out_ << '\n';
    se->getRHS()->accept(this);
    indent_ -= 4;
}

void PrintAST::visit(MulExpression* me) {
    out_ << std::string(indent_, ' ')
         << "<mulexpr>: " << me->getOperator()->getText() << '\n';
    indent_ += 4;
    me->getLHS()->accept(this); out_ << '\n';
    me->getRHS()->accept(this);
    indent_ -= 4;
}

void PrintAST::visit(DivExpression* de) {
    out_ << std::string(indent_, ' ')
         << "<mulexpr>: " << de->getOperator()->getText() << '\n';
    indent_ += 4;
    de->getLHS()->accept(this); out_ << '\n';
    de->getRHS()->accept(this);
    indent_ -= 4;
}
