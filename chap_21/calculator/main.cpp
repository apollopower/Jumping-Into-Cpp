// Write a calculator that contains the functions add, subtract,
// multipy, and divide. Should work with integers. Put function
// declarations into a seperate header file, and definitions in
// a seperate source file. Call it all here on main.cpp

#include <iostream>
#include "calculator.h"

using namespace std;

int main() {
    int x, y;
    int choice;

    cout << "Please input X value: ";
    cin >> x;

    cout << "Please input Y value: ";
    cin >> y;

    Operators num_set = newOperator(x, y);

    cout << "What would you like to do?\n";
    cout << "1. Add\n";
    cout << "2. Subtract\n";
    cout << "3. Multiply\n";
    cout << "4. Divide\n";

    cin >> choice;

    switch (choice) {
        case 1:
            cout << add(num_set) << endl;
            break;
        case 2:
            cout << subtract(num_set) << endl;
            break;
        case 3:
            cout << multiply(num_set) << endl;
            break;
        case 4:
            cout << divide(num_set) << endl;
            break;
    }
    return 0;
}