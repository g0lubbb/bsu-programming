#include "stack.h"

Stack::Stack() {
    capacity = 10;
    arr = new int[capacity];
    top = -1;
}

Stack::~Stack() {
    delete[] arr;
}

void Stack::push(int element) {
    if (top == capacity - 1) {
        int* newArr = new int[2 * capacity];
        for (int i = 0; i <= top; i++) {
            newArr[i] = arr[i];
        }
        capacity *= 2;
        delete[] arr;
        arr = newArr;
    }
    arr[++top] = element;
}

int Stack::pop() {
    if (top == -1) {
        throw "Stack is empty";
    }
    return arr[top--];
}

int& Stack::operator[](int index) {
    if (index > top || index < 0) {
        throw "Invalid index";
    }
    return arr[index];
}

bool Stack::operator<(const Stack& other) const {
    return top < other.top;
}

bool Stack::operator==(const Stack& other) const {
    if (top != other.top) {
        return false;
    }
    for (int i = 0; i <= top; i++) {
        if (arr[i] != other.arr[i]) {
            return false;
        }
    }
    return true;
}

Stack& Stack::operator=(const Stack& other) {
    if (this != &other) {
        delete[] arr;
        capacity = other.capacity;
        top = other.top;
        arr = new int[capacity];
        for (int i = 0; i <= top; i++) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}