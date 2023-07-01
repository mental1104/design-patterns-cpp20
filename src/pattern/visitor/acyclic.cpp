#include <string>
#include <sstream>
#include <iostream>

using std::ostringstream;
using std::string;

template <typename Visitable>
struct Visitor
{
    virtual void visit(Visitable& obj) = 0;
};

struct VisitorBase // marker interface
{
    virtual ~VisitorBase() = default;
};

struct Expression
{
    virtual ~Expression() = default;
    virtual void accept(VisitorBase& obj)
    {
        using EV = Visitor<Expression>;
        if (auto ev = dynamic_cast<EV*>(&obj))
            ev->visit(*this);
    }
};

struct DoubleExpression : Expression
{
    double value;
    explicit DoubleExpression(const double value)
        : value{value} {}
};

struct AdditionExpression : Expression
{
    Expression *left, *right;
    AdditionExpression(Expression* left, Expression* right) : left{left}, right{right} {}

};

struct ExpressionPrinter : VisitorBase,
                           Visitor<DoubleExpression>,
                           Visitor<AdditionExpression>
{
    void visit(DoubleExpression &obj) override;
    void visit(AdditionExpression &obj) override;
    string str() const { return oss.str(); }
private:
    ostringstream oss;
};

void ExpressionPrinter::visit(AdditionExpression& ae)
{
    std::cout << "AdditionExpression" << std::endl;
    oss << "(";
    ae.left->accept(*this);
    oss << "+";
    ae.right->accept(*this);
    oss << ")";
}

void ExpressionPrinter::visit(DoubleExpression& de){
    std::cout << "DoubleExpression" << std::endl;
    oss << de.value;
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

    printer.visit(*e);
    std::cout << printer.str() << std::endl;
}