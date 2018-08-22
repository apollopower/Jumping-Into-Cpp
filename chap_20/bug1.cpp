// This interest rate calculator is not working properly. We will
// use a debugger to fix this:

# include <iostream>

using namespace std;

double computeInterest(double base_val, double rate, int years) {
    double final_multiplier; // HINT HINT, maybe here is the bug????
    for (int i = 0 ; i < years; i++) {
        final_multiplier *= (1 + rate);
    }
    return base_val * final_multiplier;
}

int main() {
    double base_val, rate;
    int years;

    cout << "Please enter a base value: ";
    cin >> base_val;

    cout << "Enter an interest rate: ";
    cin >> rate;

    cout << "Enter the number of years to compound: ";
    cin >> years;

    cout << "After " << years << " you will have "
         << computeInterest(base_val, rate, years)
         << " dollars" << endl;
}