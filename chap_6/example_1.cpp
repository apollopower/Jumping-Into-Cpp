// An example of creating a functino that returns an integer, then using
// it on the main fuction:

# include <iostream>

using namespace std;

int add(int x, int y) {
    return x + y;
}

int main() {
    int result = add(1,2);

    cout << "Adding 1 and 2 gives us: " << result << "\n";
    cout << "Adding 3 and 4 gives us: " << add(3,4) << "\n";
    return 0;
}