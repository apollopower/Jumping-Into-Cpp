# include <iostream>

using namespace std;

int main() {
    int password;

    cout << "Please input one of two correct passwords! : \n";
    cin >> password;

    if (password == 123 || password == 6969) {
        cout << "Correct! Access Granted" << "\n";
        return 0;
    }
    cout << "Incorrect password!" << "\n";
}