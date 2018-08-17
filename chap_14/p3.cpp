// Write a program that prints out the memory addresses of each element
// in a two-dimensional array:

# import <iostream>

using namespace std;

int main() {
    // For exercises purposes, keeping matrix size 10x10

    // Making our pointer-to-pointer
    int **p_p_array = new int* [10];

    // Now storing addresses to arrays in each pointer
    for (int i = 0; i < 10; i++) {
        p_p_array[i] = new int [10];
    }

    // Loop through all elements and print their addresses:
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << & p_p_array[i][j] << endl;
        }
    }

    // Removing memory
    for (int i = 0; i < 10; i++) {
        delete [] p_p_array[i];
    }
    delete [] p_p_array;
}