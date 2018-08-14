// Simulating Randomness within a desired range:

# include <iostream>
# include <cstdlib>
# include <ctime>

using namespace std;

int randRange(int low, int high) {
    // We get a random number, get it to be between 0 and
    // the number of values in our range, then add the
    // lowest possible value
    return rand() % (high - low + 1) + low;
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 1000; i++) {
        cout << randRange(4, 10) << '\n';
    }
    return 0;
}