// Pointers

// Brief program utilizing learned features
// from intro_to_pointers.cpp

# import <iostream>

using namespace std;

int main() {
    int x;          // A normal integer
    int *p_int = NULL;     // A pointer first set to NULL

    // You should never initialize a pointer without first
    // explicitly "pointing" it somewhere. Setting it to NULL
    // Makes it clear that this pointer is not initialized.

    p_int = & x;    // "assign the address of x to p_int"

    cout << "Please enter a number: ";
    cin >> x;       // Put a value in x (*p_int also would've worked)

    cout << *p_int << endl; // Note the use of '*' to get the value

    cout << "Stored at: " << p_int << endl; // prints address of x

    *p_int = 10;    // Setting the VARIABLE (not pointer) to 10
    cout << x << endl; // Prints 10!
}