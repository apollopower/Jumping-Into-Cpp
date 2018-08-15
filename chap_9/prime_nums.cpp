// This is an example of using everything so far from chapters 2 - 8

// Here, we will write an algorithm for listing all prime numbers to
// a given integer.

# import <iostream>

using namespace std;

// Declaring the function prototype
bool isPrime(int number);

// Main call
int main() {
    int max_num;

    cout << "Please input a max number to check for all prime numbers: ";
    cin >> max_num;

    for (int i = 2; i < max_num; i++) {
        if (isPrime(i)) {
            cout << i << endl;
        }
    }
    return 0;
}

// Defining the isPrime function
bool isPrime(int number) {
    for (int i = 2; i < number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}