#include <sstream>
#include <iostream>

using std::ostringstream;

struct Expression
{
    virtual void print(ostringstream& oss) = 0;
};

struct DoubleExpression : Expression
{
    double value;
    explicit DoubleExpression(const double value)
        : value{value} {}
    void print(ostringstream& oss) { oss << value; }
};

struct AdditionExpression : Expression
{
    Expression *left, *right;
    AdditionExpression(Expression* left, Expression* right) : left{left}, right{right} {}
    void print(ostringstream& oss) override
    {
        oss << "(";
        left->print(oss);
        oss << "+";
        right->print(oss);
        oss << ")";
    }
};


int main(){
    auto e = new AdditionExpression{
        new DoubleExpression{1},
        new AdditionExpression{
            new DoubleExpression{2},
            new DoubleExpression{3}
        }
    };

    std::ostringstream oss;
    e->print(oss);
    std::cout << oss.str() << std::endl;
    return 0;
}
