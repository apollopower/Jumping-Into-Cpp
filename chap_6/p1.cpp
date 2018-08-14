// Building a simple calculator using functions outside of main()

# import <iostream>
# import <string>

using namespace std;

// Here we define and declare our operation functions:
int add(int x, int y) {return x + y;}
int subtract(int x, int y) {return x - y;}
int multiply(int x, int y) {return x * y;}
int divide(int x, int y) { return x / y; }

int main() {
    int x;
    int y;
    char operation;

    cout << "Hello! Welcome to the C++ Calculator\n";
    cout << "What operation would you like to do today? ";
    cin >> operation;

    cout << "Please declare variable X: ";
    cin >> x;
    cout << "Please declare variable Y: ";
    cin >> y;

    if (operation == '+') {
        cout << "X + Y = " << add(x,y) << "\n";
    }
    else if (operation == '-') {
        cout << "X - Y = " << subtract(x,y) << "\n";
    }
    else if (operation == '*') {
        cout << "X * Y = " << multiply(x,y) << "\n";
    }
    else if (operation == '/') {
        if (y == 0) {
            cout << "Cannot divide by 0\n";
            return 0;
        }
        cout << "X / Y = " << divide(x,y) << "\n";
    }
    else {
        cout << "Not a valid operation\n";
    }
    return 0;
}