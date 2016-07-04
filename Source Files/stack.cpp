#include "stack.h"

Stack::Stack(int size) {
    max_Stack = size;
    empty_Stack = -1;
    top = empty_Stack;
    items = new char[max_Stack];
}

Stack::~Stack() {
    delete[] items;
}

void Stack::push(char a) {
    items[++top] = a;
}

char Stack::pop() {
    return items[top--];
}

int Stack::full() {
    return top+1 == max_Stack;
}

int Stack::empty() {
    return top == empty_Stack;
}
