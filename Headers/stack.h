#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <string>

#include "stackexception.h"

template <class T, int ARRAYSIZE = 1000>
class Stack {
    private:
        T data[ARRAYSIZE];
        int top;

        void copyAll(const Stack<T, ARRAYSIZE>&);
    
    public:
        Stack();
        Stack(const Stack<T, ARRAYSIZE>&);
        
        bool isEmpty();
        bool isFull();

        void push(const T&);

        T pop();

        T getTop();

        Stack<T, ARRAYSIZE>& operator = (const Stack<T, ARRAYSIZE>&);
};

using namespace std;

// Private

template <class T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::copyAll(const Stack<T, ARRAYSIZE>& s) {
    int i(0);
    while(i <= s.top) {
        this->data[i] = s.data[i];
        i++;
    }

    this->top = s.top;
}

// Public

template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack() : top(-1) {}

template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack(const Stack<T, ARRAYSIZE>& s) {
    copyAll(s);
}

template <class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isEmpty() {
    return top == -1;
}

template <class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isFull() {
    return top == ARRAYSIZE - 1;
}

template <class T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::push(const T& e) {
    if(isFull()) {
        throw StackException("[push] The stack is full; cannot push more elements.");
    }

    data[++top] = e;
}

template <class T, int ARRAYSIZE>
T Stack<T, ARRAYSIZE>::pop() {
    if(isEmpty()) {
        throw StackException("[pop] The stack is empty; no elements to pop.");
    }

    return data[top--];
}

template <class T, int ARRAYSIZE>
T Stack<T, ARRAYSIZE>::getTop() {
    if(isEmpty()) {
        throw StackException("[pop] The stack is empty; no elements to pop.");
    }

    return data[top];
}

template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>& Stack<T, ARRAYSIZE>::operator = (const Stack<T, ARRAYSIZE>& s) {
    copyAll(s);

    return *this;
}

#endif // STACK_H_INCLUDED