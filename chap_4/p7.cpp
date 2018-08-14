// Poll Question

# include <iostream>
# include <string>

using namespace std;

// print function
void printNTimes(char c, int n) {
    // character c will be printed n times
    cout << string(n, c) << "\n";
}

int main() {
    int choice;
    int lever;
    string question = "What color do you like more?";
    int red = 0;
    int green = 0;
    int blue = 0;
    bool ask = true;

    cout << "Welcome to the poll! Please answer the following question: \n";
    
    while (ask) {
        cout << question << "\n";
        cout << "Please enter:\n1 for RED, 2 for GREEN, 3 for BLUE: ";
        cin >> choice;
        if (choice == 1 || choice == 2 || choice == 3){
            if (choice == 1) {
                red++;
            }
            else if (choice == 2) {
                green++;
            }
            else if (choice == 3) {
                blue++;
            }
            cout << "Thank you for your response!\n";
        }
        else {
            cout << "Sorry, not a valid answer.\n";
        }
        cout << "Enter '0' if you would like to conclude the poll, or any other key to continue: ";
        cin >> lever;

        if (lever == 0) {
            break;
        }
    }

    cout << "Here are the final results:\n";
    printNTimes('#', red);
    printNTimes('#', green);
    printNTimes('#', blue);
}