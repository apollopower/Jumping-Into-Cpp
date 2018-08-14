// Breaking a loop with "break"

# include <iostream>
# include <string>

using namespace std;

int main() {
    string password;
    while (true) {
        cout << "Please enter the correct password: ";
        cin >> password;

        if (password == "foo") {
            break;
        }
    }
    cout << "Correct!" << "\n";
}