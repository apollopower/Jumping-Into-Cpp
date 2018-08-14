// An example of Using Switch Case

# import <iostream>

using namespace std;

void playgame() {}

void loadgame() {}

void playmultiplayer() {}

int main() {
    int input;

    cout << "1. Play Game \n";
    cout << "2. Load Game \n";
    cout << "3. Play Multiplayer \n";
    cout << "4. Exit \n";
    cout << "Selection: ";
    cin >> input;

    switch (input) {
        case 1: // Note the colon after each case, not a semicolon
            playgame();
            break;
        case 2:
            loadgame();
            break;
        case 3:
            playmultiplayer();
            break;
        case 4:
            cout << "Thank you for playing! \n";
            break;
        default:
            cout << "Error, bad input. Quitting \n";
            break;
    }
    return 0;
}