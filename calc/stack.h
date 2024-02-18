#pragma once
class Stack {
private:
    int* arr;
    int top;
    int capacity;
public:
    Stack();
    ~Stack();

    void push(int element);
    int pop();
    int getTop() { return top; };
    int& operator[](int index);

    bool operator<(const Stack& other) const;
    bool operator==(const Stack& other) const;
    Stack& operator=(const Stack& other);
};
