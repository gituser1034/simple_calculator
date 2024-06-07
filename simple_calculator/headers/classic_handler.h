#ifndef CLASSICHANDLER_H
#define CLASSICHANDLER_H

using namespace std;
#include <string>

class ClassicHandler{
    public:
        ClassicHandler(){}
        ~ClassicHandler(){}
        void intro();
        void recieve_equation();
        void calculate();
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
        // double sum = 0;
        // double subtractor = 0;
        // double multiplier = 0;
        // double divider = 0;
        double total = 0;
};

#endif