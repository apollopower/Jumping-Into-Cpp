// Arrays

// Demonstration using for loops to create multiplication
// tables and store the results in a two-dimensional array

# include <iostream>

using namespace std;

int main() {
    int array[8][8]; // 2D array shaped like a chessboard

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // Set each element to the product value of our iteration
            array[i][j] = i * j;
        }
    }

    cout << "Multiplication Table: \n";

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << "[" << i << "][" << j << "] = ";
            cout << array[i][j] << " \n";
        }
    }
}