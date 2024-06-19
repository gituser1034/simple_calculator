#ifndef CLASSICHANDLER_H
#define CLASSICHANDLER_H

#include "../headers/queue.h"
#include "../headers/stack.h"

using namespace std;
#include <string>

class ClassicHandler{
    public:
        ClassicHandler(){}
        ~ClassicHandler(){}
        void intro();
        void recieve_equation();
        void calculate();
        // Operations when closed bracket encountered
        void bracket_checker(char value);
        // Operations when a number is encountered
        void digit_checker(char value);
        void shunting_yard_calculate();
        // Char converted to int for purposes of being in range 0-9
        // verify correct range with is_digit
        int to_int_counterpart(char value) {return int(value)-48;}
        bool is_digit(int num);
        // Checking if operator or bracket or . 
        bool check_symbol(int num);

    private:
        string equation;
        int equation_length = equation.size();
        // Equation iterator
        int i = 0;
        // double sum = 0;
        // double subtractor = 0;
        // double multiplier = 0;
        // double divider = 0;
        double total = 0;
        Stack stack;
        Queue queue;
};

#endif