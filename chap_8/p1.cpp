// Simulate a coin flip:

# include <iostream>
# include <cstdlib>
# include <ctime>

using namespace std;

int randRange(int low, int high) {
    return rand() % (high - low + 1) + low;
}

int main() {
    int input;
    int coin;

    cout << "Welcome to coin flip! \n";

    while (true) {
        cout << "Press 1 to flip a coin. Press anything else to quit: \n";
        cin >> input;
        if (input != 1) { break; }
        coin = randRange(1,2);
        if (coin == 1) {
            cout << "Heads! \n";
        }
        else {
            cout << "Tails! \n";
        }
        cout << " \n";
    }
    cout << "Goodbye! \n";
    return 0;
}