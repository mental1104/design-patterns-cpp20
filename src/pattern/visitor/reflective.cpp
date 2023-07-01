#include <sstream>
#include <iostream>
#include <string>

using std::string;
using std::ostringstream;

struct Expression
{
    virtual ~Expression() = default;
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

struct ExpressionPrinter
{
    void print(Expression* e)
    {
        if(auto de = dynamic_cast<DoubleExpression*>(e))
        {   
            oss << de->value;
        } 
        else if (auto ae = dynamic_cast<AdditionExpression*>(e))
        {
            oss << "(";
            print(ae->left);
            oss << "+";
            print(ae->right);
            oss << ")";
        }
    }

    string str() const { 
        return oss.str();
    }

private:
    ostringstream oss;
    
};

int main(){
    ExpressionPrinter printer;
    auto e = new AdditionExpression{
        new DoubleExpression{1},
        new AdditionExpression{
            new DoubleExpression{2},
            new DoubleExpression{3}
        }
    };

    printer.print(e);
    std::cout << printer.str() << std::endl;
}