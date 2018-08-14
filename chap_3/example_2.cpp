# include <iostream>
# include <string>

using namespace std;

int main() {
    string password;

    cout << "Please enter the password: ";
    cin >> password;

    if (password == "password") {
        cout << "Access granted!" << "\n";
    }
    else {
        cout << "Access denied. Wrong password" << "\n";
        // returning is a convinient way to stop the program
        return 0;
    }
    // continue onward!
}