// Recursion

// To demonstrate the power of recursion, we write a function that
// prints our the numbers 123456789987654321

# include <iostream>

using namespace std;

void printNum(int num) {
    // The two calls in this function to cout will sandwich an inner
    // sequence containing the numbers (num + 1)...99...(num + 1)
    cout << num;

    // While begin is less than 9, we need to recursively print the
    // sequence for (num+1) ... 99 ... (num+1)
    if (num < 9) {
        printNum(num + 1);
    }

    cout << num << endl;
}

int main() {
    printNum(1);
}