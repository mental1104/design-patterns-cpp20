#include <sstream>
#include <string>
#include <iostream>

using std::ostringstream;
using std::string;

struct DoubleExpression;
struct AdditionExpression;

struct ExpressionVisitor {
    virtual void visit(DoubleExpression* de) = 0;
    virtual void visit(AdditionExpression* ae) = 0;
};

struct Expression
{
    virtual void accept(ExpressionVisitor* visitor) = 0;
};

struct DoubleExpression : Expression
{
    double value;
    explicit DoubleExpression(const double value)
        : value{value} {}
    void accept(ExpressionVisitor* visitor) override {  visitor->visit(this); }
};

struct AdditionExpression : Expression
{
    Expression *left, *right;
    AdditionExpression(Expression* left, Expression* right) : left{left}, right{right} {}
    void accept(ExpressionVisitor* visitor) override {  visitor->visit(this); }
};



struct ExpressionPrinter : ExpressionVisitor
{
    ostringstream oss;
    string str() const { return oss.str(); }
    void visit(DoubleExpression* de) override;
    void visit(AdditionExpression* ae) override;
};

void ExpressionPrinter::visit(AdditionExpression* ae)
{
    oss << "(";
    ae->left->accept(this);
    oss << "+";
    ae->right->accept(this);
    oss << ")";
}

void ExpressionPrinter::visit(DoubleExpression* de){
    oss << de->value;
}

struct ExpressionEvaluator : ExpressionVisitor
{
    double result;
    void visit(DoubleExpression* de) override;
    void visit(AdditionExpression* ae) override;
};


void ExpressionEvaluator::visit(DoubleExpression* de)
{
    result = de->value;
}


void ExpressionEvaluator::visit(AdditionExpression* ae)
{
    ae->left->accept(this);
    auto temp = result;
    ae->right->accept(this);
    result += temp;
}


int main()
{
    auto e = new AdditionExpression{
        new DoubleExpression{1},
        new AdditionExpression{
            new DoubleExpression{2},
            new DoubleExpression{3}
        }
    };

    ostringstream oss;
    ExpressionPrinter printer;
    ExpressionEvaluator evaluator;
    printer.visit(e);
    evaluator.visit(e);
    std::cout << printer.str() << " = " << evaluator.result << std::endl;
}