// Write a function that builds a two-dimensional multiplication table with
// arguments for length & width for the two dimensions

# include <iostream>

using namespace std;

int **multiplication_tables(int length, int width) {
    int **p_p_table = new int* [length];

    // Now for each address store the address of an array size width
    for (int i = 0; i < length; i++) {
        p_p_table[i] = new int [width];
    }

    // Store multiplication values of indexes into each element:
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            p_p_table[i][j] = i * j;
        }
    }

    return p_p_table;
}

int main() {
    int length;
    int width;

    cout << "Please provide a length: ";
    cin >> length;
    cout << "Please provide a width: ";
    cin >> width;

    int **p_p_table = multiplication_tables(length, width);

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            cout << i << " * " << j << " = " << p_p_table[i][j] << endl;
        }
    }

    // Now to return the memory:
    for (int i = 0; i < length; i++) {
        delete [] p_p_table[i];
    }

    delete p_p_table;
}