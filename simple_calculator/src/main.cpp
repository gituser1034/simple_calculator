#include <iostream>
#include <string>
#include <vector>
#include "../headers/classic_handler.h"
#include "classic_handler.cpp"
using namespace std;

int main(){
    ClassicHandler classic_handler;

    cout << "Welcome to Simple Calculator!\nSelect a menu item below to start"
            " your calculating journey!" << endl;

    vector<string> menu = {"1. Classic", "2. Factoring", "3. Integrals", "4. Unit Conversions"};
    int menu_num;

    for (int i = 0; i < menu.size(); i++){
        cout << menu[i] << endl;
    }

    cout << "\nAt any point type back to reset!\n" << endl;
    
    bool menu_flag = false;

    // Allow user to input calculator type with error catching for ints
    // could switch to string data type and convert to int to catch string input errors as well
    while (menu_flag == false){
        cout << "Enter a number: ";
        cin >> menu_num;

        if (menu_num >=1 && menu_num <= 4) {
            menu_flag = true;
            break;
        }
        else{
            cout << "Incorrect entry! Please try again!" << endl;
        }
    }
    
    cout << "You chose: " << menu[menu_num-1] << "\n" << endl;

    // Take user to correct calculator type based on selection 
    switch (menu_num) {
        case 1: 
            classic_handler.intro();
            classic_handler.recieve_equation();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
    }


}