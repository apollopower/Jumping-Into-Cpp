// Multidimensional Arrays w/ Pointers

# include <iostream>

using namespace std;

int main() {
    // Creating our "pointer-to-pointer". Notice the
    // ** and p_p_ syntax
    int **p_p_tictactoe;

    // Notice the array we are making is an int*, since
    // we are allocating an array of pointers
    p_p_tictactoe = new int* [3];

    // Now make each pointer store the address of an array of integers
    for (int i = 0; i < 3; i++) {
        p_p_tictactoe[i] = new int[3];
    }

    // We can now use the allocated memory just like a two-dimensional
    // array. For example, we can initialize the entire board with a
    // pair of for loops:
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            p_p_tictactoe[i][j] = 0;
        }
    }

    // To free the memory, we go in the opposite order that we
    // initialized it. First free each row, then free the pointer
    // that holds the rows:
    for (int i = 0; i < 3; i ++) {
        delete [] p_p_tictactoe[i];
    }
    delete [] p_p_tictactoe;
}
