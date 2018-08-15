// This is an example of using everything so far from chapters 2 - 8

// Here, we write an algorithm to translate an integer into english

# include <iostream>
# include <string>

using namespace std;

int main() {
    int number;

    cout << "Provide an integer, between -999,999 to 999,999, to transform to text: \n";
    cin >> number

    cout << numToEnglish(number) << endl;
}

numToEnglish(int number) {
    // Split into 3 digit chunks
    int chunk1;
    int chunk2;
}