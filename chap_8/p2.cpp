// Number Guesser Program

# import <iostream>
# import <cstdlib>
# import <ctime>

using namespace std;

int randRange(int low, int high) {
    return rand() % (high - low + 1) + low;
}

int main() {
    int number;
    int guess;
    int tries = 0;

    cout << "Welcome to the number guesser! \n";
    cout << "Please input a number equal to or greater than 1 for me to guess: ";
    cin >> number;

    cout << "Alright! Now trying to guess \n";

    while (true) {
        guess = randRange(1, number);
        tries++;
        if (guess == number) { break; }
        else {
            cout << "It's not " << guess << "...\n";
        }
    }
    cout << " \n";
    cout << "... got it! \n";
    cout << "Your number was " << guess << " :) \n";
    cout << "And it only took me " << tries << " tries! \n";
}