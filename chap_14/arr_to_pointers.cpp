// Dynamic Memory Allocation

# import <iostream>

using namespace std;

int main() {
    // Creating array size 8
    int numbers[8];

    // Creating pointer for an array. Note that with
    // arrays, you do not require the '&' to explicitly
    // point to memory:
    int* p_numbers = numbers;
    cout << p_numbers << endl;          // prints memory address

    // And now use p_numbers just like an array:
    for (int i = 0; i < 8; i++) {
        p_numbers[i] = i;
        cout << p_numbers[i] << endl;   // prints out i 
    }
    cout << p_numbers << endl;          // prints memory address
}

// IT IS IMPORTANT TO UNDERSTAND THAT ARRAYS ARE NOT
// POINTERS, BUT THAT ARRAYS CAN BE ASSIGNED TO POINTERS