#include <iostream>
#include <string>
#include "../headers/classic_handler.h"
#include "../headers/queue.h"
#include "../headers/stack.h"
#include "queue.cpp"
#include "stack.cpp"
#include <vector>
using namespace std;

// Put functions for classic handler
void ClassicHandler::intro(){
    cout << "Type * for multiplication, / for division, + for addition, - for subtraction, ^ for to the power,\n" 
            "root() for square root, x_root for xth root (replace x with desired root) "
            "and Include brackets for complex bedmas operations.\n" 
            "Spaces not needed. Eg. (5+5)/root(3)\n" << endl;
}

void ClassicHandler::recieve_equation(){
    cout << "Enter equation: ";
    cin >> equation;
    cout << equation << endl;
}

// Checking if a char is a digit, in the correct ascii 0-9 range
bool ClassicHandler::is_digit(int num){
    // int num = to_int_counterpart(value);
    if (num >= 0 && num <= 9){
        return true;
    }
    else {
        return false;
    }
}

// Checking if valid symbol - ascii range from 40-46 inclusive, and not 44
bool ClassicHandler::check_symbol(int num){
    if (num >= 40 && num <= 46 && num != 44){
        return true;
    }
    else{
        return false;
    }
}

// Checking if value is a closed bracket, if so want to clear stack and add everything
// from it to queue
void ClassicHandler::bracket_checker(char value){
    char popped;
    if (value == ')'){
        while (!(stack.is_empty())){
            popped = stack.pop();
            if (value != '(' && value != ')'){
                queue.enqueue(popped);
            }
        }
    }
}

void ClassicHandler::digit_checker(char value){
    // iterator for creating num from seperate digits
    int j = 0;
    int final_num = 0;
    bool digits_done = false;
    // Assuming num is a digit, verifying soon
    final_num = value;
    j = i+1;

    // If digit want to enqueue, but first check for more digits if its a bigger number (ie 152)
    if (is_digit(final_num)){
        while (!digits_done){
            // Checking next value and making sure in eqn bounds
            if (j < equation_length){
                if (is_digit(equation[j])){
                    final_num = (final_num * 10) + equation[j];
                    j++;
                    // updating i to skip digits already encountered with j from inner loop
                    i = j;
                }
                else{
                    digits_done;
                }
            }
        }
        queue.enqueue(final_num);
    }
}

// Gonna have to break this up into multiple functions possibly

// Iterate over equation, if operator (if statement for diff ops) put on stack
// if number put on queue
// if you get add/sub and the top of stack has a mul or div, enqueue mul/divide and push add sub to stack
// if val is a closed bracket, pop off stack and enqueue ops one by one, discarding the brackets.

// next part later will evaluate the queue

// if number encountered, then do for loop checking for subsequent nums to create proper number
// for queue, may need to turn digit to char and have a char queue, then check if item is a number to convert back to int later
void ClassicHandler::shunting_yard_calculate(){
    // iterator for creating num from seperate digits
    int j = 0;

    int final_num = 0;
    bool digits_done = false;
    char popped; 

    for (i; i < equation_length; i++){
        // Check if proper calculating symbol (+, -, etc.)

        // if add/sub is encountered and the top of stack has a mul or div, pop mul/div from stack and enqueue it
        // push add/sub onto stack
        if (equation[i] == '+' || equation[i] == '-'){
            if (stack.get_last() != '*' && stack.get_last() != '/'){
                stack.push(equation[i]);
            }
            else if(stack.get_last() == '*' || stack.get_last() == '/'){
                popped = stack.pop();
                queue.enqueue(popped);
                stack.push(equation[i]);
            }
        }
        
        if (check_symbol(equation[i]) && (equation[i] != '+' && equation[i] != '-')) {
            stack.push(equation[i]);
        }

        // Check for closed bracket
        bracket_checker(equation[i]);

        // Check if num and do operations accordingly
        digit_checker(equation[i]);
    }
}

// Uses entered equation, parses it, calculates returning the answer
// Need to take string of ie (5+5)*20, break down components in bedmas fashion and calculate

// Need to scratch this and do something with a stack, and abstract syntax tree
// void ClassicHandler::calculate(){
//     // double sum = 0;
//     // double subtractor = 0;
//     // double multiplier = 0;
//     // double divider = 0;

//     // First simple example 5+5+5... works
//     // Possible issues to account for later - 5+, 5+#, when 5 is added with nothing or a value thats not an int
//     // For above could have else with error
//     equation = "5+5/10";
//     int num_version = int(equation[0]-48);
//     int previous_total = 0;
//     char previous_operator;
//     int full_num;

//     if (check_num(num_version)){
//         total = num_version;
//         previous_total = num_version;
//     }

//     for (int i = 1; i < equation.size(); i++){
//         // Wanna look for brackets then perform op inside those brackets first. 
//         // need an array to store the numbers encountered
//         // if (equation[i] == '('){
//         //     break;
//         // }

//         // So far only works for single numbers 0-9, not 10 or 500, and only works with one operator per equation
//         if (equation[i] == '+' && i < equation.size()-1){
//             total += (int(equation[i+1]-48));
//             previous_operator = equation[i];
//             full_num = 0;
//         }
//         else if (equation[i] == '-' && i < equation.size()-1){
//             total -= (int(equation[i+1]-48));
//             previous_operator = equation[i];
//             full_num = 0;
//         }
//         else if (equation[i] == '*' && i < equation.size()-1){
//             total *= (int(equation[i+1]-48));
//             previous_operator = equation[i];
//             full_num = 0;
//         }
//         else if (equation[i] == '/' && i < equation.size()-1){
//             total /= (int(equation[i+1]-48));
//             previous_operator = equation[i];
//             full_num = 0;
//         }
//         else if (check_num(equation[i])){
//             // undo the previous sum and create the correct digit
//             total = previous_total;
//             // When theres 
//             if (full_num != 0){
//                 full_num = full_num + (int(equation[i])-48);
//             }
//             else{
//                 // Multiply previous digit by 10 because if another is on 
//                 // Doesn't work because if we have 100, will get 1*10 for 10, then will just add 0, but will add
//                 // 0 again to so will have 10 when it should be 100
//                 full_num = (int(equation[i-1])-48)*10 + (int(equation[i]-48));
//             }
//         }

//         // Need to have else, concatenate number together like 50 
        
//     }
//     cout << total << endl;

// }

int main(){
    // calculate tester

    ClassicHandler classic;
    classic.calculate();
}