// An example of only declaring a function with a 
// Prototype call:

# include <iostream>

using namespace std;

// Here is our function prototype
int add(int x, int y);

int main() {
    int result = add(1,2);
    cout << "The result of adding 1 and 2 is: " << result << "\n";
}

// Notice that with declarations, we can define a function AFTER we 
// call it in main()
int add(int x, int y) {
    return x + y;
}