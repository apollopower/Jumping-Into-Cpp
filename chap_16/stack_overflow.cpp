// Causing a stack overflow, seeing how many function calls
// will take to run out of stack space:

# include <iostream>

using namespace std;

void recurse(int count) { // Each call will get its own count
    cout << count<< endl;

    recurse(count + 1);
}

int main() {
    // First function call, so it starts at one:
    recurse(1);
}