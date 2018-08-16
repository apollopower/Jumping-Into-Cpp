// Pointers allow you to pass the address of a
// local variable into a function, which can then
// modify the local variable.

// Here we demostrante this with a pair of functions
// that swap values stored in two variables:

# import <iostream>

using namespace std;

// SPOLIER ALERT: This one won't work!
void swap1(int left, int right) {
    int temp = left;
    left = right;
    right = temp;
}
// But this one will :)
void swap2(int *p_left, int *p_right) {
    int temp = *p_left;
    *p_left = *p_right;
    *p_right = temp;
}

// swap1 just switches the values of two variables local
// to the swap function.

// swap1 can't touch the values passed into it because they
// store copies of the original values.

// swap2 HAS access to the memory that backs the two
// variables, so when it performs its switch, it writes
// into the memory of variables x and y.


// USING A REFERENCE:

// A reference is a variable that points to another variable,
// sharing the same backing memory. It's like a pointer,
// without the memory-changing power of a pointer!

// notice the use of '&' with the variable to declare it
// as a reference variable:
void swap3(int &left, int &right) {
    int temp = left;
    left = right;
    right = temp;
}

// References are much simpler in this use case
// (where we don't care about handling the memory)

int main() {
    int x = 1, y = 2;
    cout << x << " " << y << "\n";
    swap1(x, y);
    cout << x << " " << y << "\n";
    swap2(& x, & y);
    cout << x << " " << y << "\n";
    swap3(x, y);
    cout << x << " " << y << "\n";
}