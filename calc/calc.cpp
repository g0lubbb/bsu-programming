#include "calc.h"

Calculator::Calculator() {

}

void Calculator::acceptExpression(std::string expression) {
    this->expression = expression;
    stack.push('#');
}

bool Calculator::isExpressionValid() {
    stack.push('#');
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];
        if (isOperator(c)) {
            if (c == '(') {
                stack.push('(');
            }
            else if (c == ')') {
                while (stack[stack.pop()] != '(');
            }
            else {
                while (getOperatorPrecedence(stack[stack.getTop()]) >= getOperatorPrecedence(c)) {
                    stack.pop();
                }
                stack.push(c);
            }
        }
        else {
            if (!isdigit(c)) {
                return false;
            }
        }
    }
    return stack[stack.pop()] == '#';
}

int Calculator::calculate() {
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];
        if (isdigit(c)) {
            stack.push(c - '0');
        }
        else if (isOperator(c)) {
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            stack.push(calculateOperator(c, operand1, operand2));
        }
    }
    return stack.pop();
}

int Calculator::calculateOperator(char op, int operand1, int operand2) {
    if (op == '+') {
        return operand1 + operand2;
    }
    else if (op == '-') {
        return operand1 - operand2;
    }
    else if (op == '*') {
        return operand1 * operand2;
    }
    else if (op == '/') {
        return operand1 / operand2;
    }
}