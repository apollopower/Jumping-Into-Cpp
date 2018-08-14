# import <iostream>
# import <string>

using namespace std;

int main() {
    int user1;
    int user2;

    cout << "Enter User 1's age: ";
    cin >> user1;
    cout << "Enter User 2's age: ";
    cin >> user2;

    if (user1 > user2) {
        cout << "User 1 is older" << "\n";
    }
    else if (user2 > user1) {
        cout << "User 2 is older" << "\n";
    }
    else {
        cout << "Both users are the same age" << "\n";
    }
    return 0;
}