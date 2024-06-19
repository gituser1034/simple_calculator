#ifndef STACK_H
#define STACK_H
#include <vector>
using namespace std;

// LIFO data structure for storing data
class Stack {
    public:
        Stack(){}
        ~Stack(){}
        // Add item
        void push(char value);
        // Removes and returns last added value
        char pop();
        // Get char that was last added to the stack
        char get_last();
        void print();
        bool is_empty();
    private:
        vector<char> stack;
};

#endif