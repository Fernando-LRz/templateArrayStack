#include <iostream>
#include <random>
#include <chrono>
#include <functional>

#include "stack.h"

using namespace std;

int main() {
    default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(1, 999);
    auto dice = bind(distribution, generator);

    Stack<int, 10> myStack;
    int value;

    cout << endl;

    for(int i(0); i < 10; i++) {
        value = dice();

        cout << "Pushing: " << value << endl;

        myStack.push(value);
    }

    cout << endl << endl;

    // Stack<int, 10> myOtherStack;
    // myOtherStack = myStack;

    Stack<int, 10> myOtherStack(myStack);

    cout << "Clearing the stack..." << endl << endl;

    while(!myStack.isEmpty()) {
        cout << "Popping: " << myStack.pop() << endl;
    }

    cout << endl << endl;

    cout << "Clearing the other stack..." << endl << endl;

    while(!myOtherStack.isEmpty()) {
        cout << "Popping: " << myOtherStack.pop() << endl;
    }

    cout << endl << endl;
    return 0;
}