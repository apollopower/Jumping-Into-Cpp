# include <iostream>
# include <string>

using namespace std;

int main() {
    int num;

    cout << "Please enter a number: ";  
    cin >> num;

    if (num > 10) {
        cout << "Wow, that's a big number!\n";
    }
    else if (num == 10) {
        cout << "Your number equals 10. Shocker!\n";
    }
    else {
        cout << "Thats a pretty small number.\n";
    }
}