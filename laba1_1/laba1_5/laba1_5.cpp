#include <iostream>

using namespace std;

class Expression {
public:
    virtual double evaluate() const = 0;
    virtual ~Expression() {}
};

class Number : public Expression {
public:
    Number(double value) : value(value) {}
    double evaluate() const 
    { 
        return value; 
    }
    ~Number() {}

private:
    double value;
};

class BinaryOperation : public Expression {
public:
    BinaryOperation(Expression const* left, char op, Expression const* right) : right(right), left(left), op(op) {}

    double evaluate() const 
    {
        switch (op) {
        case '+':
            return (left->evaluate() + right->evaluate());
        case '-':
            return (left->evaluate() - right->evaluate());
        case '*':
            return (left->evaluate() * right->evaluate());
        case '/':
            return (left->evaluate() / right->evaluate());
        }
    }
    ~BinaryOperation() {
        delete left;
        delete right;
    }

private:
    Expression const* right;
    Expression const* left;
    char op; 
};

bool check_equals(Expression const* left, Expression const* right)
{
    return (*(size_t**)left) == (*(size_t**)right);
}

int main() {
    Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));

    Expression* expr = new BinaryOperation(new Number(3), '+', sube);

    Expression* num = new Number(5);
    
    delete expr;
}
