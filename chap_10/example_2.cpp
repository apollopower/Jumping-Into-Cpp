// Defining a function which takes an array, without a
// predetermined length.

// Here is an example with the sum_array function:

# include <iostream>

using namespace std;

int sumArray(int values[], int size) {
    int sum = 0;
    // The array will stop when i == size.
    // Remember, the last element of an array is
    // its size - 1

    for (int i = 0; i < size; i++) {
        sum += values[i];
    }

    return sum;
}

int main() {
    int values[10]; // Creating array with size 10

    // Now filling in the elements in the empty array
    for (int i = 0; i < 10; i++) {
        cout << "Enter value for index " << i << ": ";
        cin >> values[i];
    }

    cout << sumArray(values,10) << endl;
}