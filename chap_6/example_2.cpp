// An example of using global variables: Just place them outside
// of functions, at the highest level of your script:

# import <iostream>

using namespace std;

// Our global variable
int count_of_function_calls = 0;

void fun() {
    // Calling it inside this function
    count_of_function_calls++;
}

int main() {
    fun();
    fun();
    fun();
    // Calling it in here too!
    cout << "Function fun was called " << count_of_function_calls << " times! \n";
}