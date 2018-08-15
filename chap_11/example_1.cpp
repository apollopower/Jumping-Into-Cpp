// Structures

// Example program that demonstrates reading in the names
// of five players in a game, which will combine arrays
// and structures:

# include <iostream>

using namespace std;

// Creating our player info structure
struct PlayerInfo {
    string name;
    int skill_level;
};

int main() {
    // Like normal variable types, we can make arrays of
    // structures

    // declaring our new PlayerInfo instance, array size 5
    PlayerInfo players[5];

    for (int i = 0; i < 5; i++) {
        cout << "Please enter the name for player " << i + 1 << ": \n";
        // First access the element of the array, using
        // normal array syntax; then access the field
        // of the structure using the '.' syntax
        cin >> players[i].name;
        cout << "Please enter the skill level for "
             << players[i].name << ": \n";
        cin >> players[i].skill_level;
    }

    // Now to show the info for all our players:
    for (int i = 0; i < 5; i++) {
        cout << players[i].name
             << " is at skill level "
             << players[i].skill_level << "\n";
    }
}