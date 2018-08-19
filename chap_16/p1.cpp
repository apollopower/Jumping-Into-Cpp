// Write a recursice algorithm to compute the power function:
// pow(x,y) = x^y

# include <iostream>

using namespace std;

int power(int num, int exponent) {
    if (exponent == 1) {
        return num;
    }
    // Not accurate for negative numbers, but not point of exercise
    else if (exponent <= 0 ) {
        return 1;
    }
    return num * power(num, exponent - 1);
}

int main() {
    int num;
    int exponent;
    cout << "Number? ";
    cin >> num;
    cout << "Exponent? ";
    cin >> exponent;

    cout << power(num, exponent) << endl;
}