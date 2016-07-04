
#ifndef STACKS_CPP_STACK_H
#define STACKS_CPP_STACK_H

class Stack {
    int max_Stack;
    int empty_Stack;
    int top;

    char* items;

public:
    Stack(int);
    ~Stack();

    void push(char);
    char pop();

    int empty();
    int full();

};

#endif //STACKS_CPP_STACK_H
