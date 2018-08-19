// Example of recursion by calculating the factorial
// of a given number. Factorial :

// Factorial(x) = x * (x - 1) * (x - 2) ... * 1

# include <iostream>

using namespace std;

int factorial(int x) {
    // cout << "Current x value: " << x <<endl;
    // Our base case:
    if (x == 1) {
        return 1;
    }
    // Starts coming up each level, providing
    // the product of each previous factorial
    return x * factorial(x - 1);
}

// We keep going a level deeper until we reach 1. When we do,
// we go up a level where x = 2. Since factorial(2 - 1) (the lowest
// level where x = 1) returned 1, the final function returns
// 2 (current val) * 1 (returned val from function).


// This process continues for each level coming back up. Since
// x = 2 level is now returned (with return value of 2), x= 3 level
// now continues. So we get 3 (current val) * 2 (returned val), which
// then returns 6 for the next level (x = 4). So in the next level, the
// last line calulcate 4 (current val) times 6 (returned val). And
// so on and so on... until we reach the original x value

// We will also workout facatorial function, ITERATIVELY
int iterative_factorial(int x) {
    int total = x;
    while (x > 1) {
        x--;
        total *= x;
    }
    return total;
}

int main() {
    cout << factorial(10) << endl;
    cout << iterative_factorial(10) << endl;
    return 0;
}