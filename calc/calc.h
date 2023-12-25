#pragma once

#include <string>
#include "stack.h"

class Calculator {
public:
    Calculator();
    void acceptExpression(std::string expression);
    bool isExpressionValid();
    int calculate();

private:
    std::string expression;
    Stack stack;

    int calculateOperator(char op, int operand1, int operand2);
    bool isOperator(char c);
    int getOperatorPrecedence(char op);
};
