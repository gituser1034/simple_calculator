#include "../headers/stack.h"
#include <iostream>
#include <vector>

using namespace std;

// Add to beginning of stack
void Stack::push(char value){
    stack.push_back(value);
}

// Remove item from end of stack
void Stack::pop(){
    stack.pop_back();
}

char Stack::get_last(){
    return stack[stack.size()-1];
}

void Stack::print(){
    for (int i = 0; i < stack.size(); i++){
        cout << stack[i];
    }
    cout << endl;
}

int main(){
    // Stack stack;
    // stack.push('a');
    // stack.push('b');
    // cout << stack.get_last() << endl;
}