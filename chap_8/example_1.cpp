// Generating Random Numbers using 'srand'

# include <iostream>
# include <cstdlib>
# include <ctime>

using namespace std;

int main() {
    // Call just once, at the very start of your program
    srand(time(NULL));
    cout << rand() << '\n';
}