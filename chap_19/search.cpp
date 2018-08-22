// This sample code searched for every instance of the string
// "cat" in a given string and counts the total number of 
// instances

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    int cat_appearences = 0;

    cout << "Please enter a line of text: \n";
    getline(cin, input, '\n');

    int i = 0;
    for (i = input.find("cat", 0);
        i != string::npos;
        i = input.find("cat", i))
    {
        cat_appearences++;
        // Moce past the last discovered instance to avoid
        // finding the same string again
        i++;
    }
    cout << "The word cat appears " << cat_appearences << " times" << endl;
}