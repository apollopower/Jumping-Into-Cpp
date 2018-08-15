// Insertion Sort algorithm

# include <iostream>
# include <cstdlib>
# include <ctime>

using namespace std;

// Declaring function prototypes
void sort(int array[], int array_size);
int findSmallestRemainingElement(int array[], int array_size, int index);
void swap(int array[], int first_index, int second_index);
void displayArray(int array[], int array_size);

int main() {
    int values[10]; // Declaring values array (size 100)

    srand(time(NULL)); // Setting Random Seed

    for (int i = 0; i < 10; i++) {
        values[i] = rand() % 100; // Keeping values small for legibility
    }

    cout << "Original array: ";
    displayArray(values, 10); // Helper function to show the array
    cout << " \n";

    // Our "magical" insertion sort algorithm
    sort(values, 10);

    cout << "Sorted array: ";
    displayArray(values, 10); // Array should now be sorted
    cout << " \n";
}

void sort(int array[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        // We know we need to find the smallest (remaining) element
        int index = findSmallestRemainingElement(array, array_size, i);
        // Then we need to swap current element with smallest to sort
        swap(array, i, index);
    }
}

// Defining how to find smallest remaining element
int findSmallestRemainingElement(int array[], int array_size, int index) {
    int index_of_smallest_value = index;

    for (int i = index + 1; i < array_size; i++) {
        if (array[i] < array[index_of_smallest_value]) {
            index_of_smallest_value = i;
        }
    }

    return index_of_smallest_value;
}

// Defining our swap function:
// Since a function can modify the original array that is passed to it,
// we can do this by exchanging the two values, using a temporary
// variable to hold the first value that is overwritten
void swap(int array[], int first_index, int second_index) {
    int temp = array[first_index];
    array[first_index] = array[second_index];
    array[second_index] = temp;
}

// Our helper function to visualize the array
void displayArray(int array[], int array_size) {
    cout << "["; //Opening a brack to show beginning of array

    for (int i = 0; i < array_size; i++) {
        // Here is a common pattern for nicely formatting lists:
        // Check if we're past the first element, and if so,
        // append a comma before the element
        if (i != 0) {
            cout << ", ";
        }
        cout << array[i];
    }

    cout << "]"; // closing bracket to show end of array
}