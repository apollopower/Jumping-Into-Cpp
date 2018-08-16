// Pointers

// '&' is the 'address-of' operator, and is used to return
// the memory address of a variable:

# import <iostream>

using namespace std;

int main() {
    int x = 5;

    // Pointer to x (note the '&'), note the '*' which specifies
    // this variable as a pointer:
    int *p_pointer_to_integer = & x;

    cout << p_pointer_to_integer << endl; // prints address of x
    // this is equivalent of: cout << & x

    cout << *p_pointer_to_integer << endl; // prints VALUE of x
    // note the use of the '*' on this variable call,
    // which says, "follow the pointer and get the
    // value stored in the memory that this is pointed to."
    // This is known as DEREFERENCING

    // Dereferencing a variable also lets you set a
    // value into a memory address:
    *p_pointer_to_integer = 7; // x is now 7!
    cout << x << endl;

    // IN SHORT
    // Pointers: pointer variable points to address.
    // To get the value stored at the address, use '*'

    // Normal Variable: To retrieve the address of a normal
    // variable, user the ampersand '&'


}