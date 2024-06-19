#include "../headers/stack.h"
#include <iostream>
#include <vector>

using namespace std;

// Add to beginning of stack
void Stack::push(char value){
    stack.push_back(value);
}

// Remove item from end of stack, return removed item as well
char Stack::pop(){
    char popped = get_last();
    stack.pop_back();
    return popped;
}

// Get last value added to stack
char Stack::get_last(){
    return stack[stack.size()-1];
}

void Stack::print(){
    for (int i = 0; i < stack.size(); i++){
        cout << stack[i];
    }
    cout << endl;
}

// Checks if stack is empty
bool Stack::is_empty(){
    if (stack.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    Stack stack;
    stack.push('a');
    stack.push('b');
    cout << stack.get_last() << endl;
}