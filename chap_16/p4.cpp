// Write a recursive function that takes a sorted array
// and a target element and returns the index of that
// element in the array (return -1 if element does not exist)

# include <iostream>

using namespace std;

int findElement(int arr[], int arr_size, int element);
int binaryFindElement(int arr[], int first, int last, int element);

int main()
{
    
    int arr[10]; // Building standard, fixed array
    int element; // Will become requested element to search for
    

    // Making elements equal index value + 1 (sorted array)
    cout << "Building array...\n";
    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1;
        // Showing element of array
        cout << arr[i] << endl;
    }

    cout << "What element would you like to find? ";
    cin >> element;

    // Look for element and return index
    cout << findElement(arr, 10, element) << endl;

    cout << "Binary search...\n";

    cout << binaryFindElement(arr, arr[0], arr[9], element) << endl;

}

// O(n) time complexity
int findElement(int arr[], int arr_size, int element) {
    int current_idx = arr_size - 1;

    if (arr[current_idx] == element) {
        // We found the element! Return the current index
        cout << "Found element!\n";
        return current_idx;
    }
    else if (current_idx == 0) {
        // We did not find the element
        cout << "Did not find element\n";
        return -1;
    }
    // Recursive call:
    return findElement(arr, current_idx, element);
}

// O(log n) time complexity (binary search)
int binaryFindElement(int arr[], int first, int last, int element) {

    if (first <= last) {
        int target = (first + last) / 2; 
        if (element == arr[target]) {
            cout << "Found element!\n";
            return target;
        }
        else if (element < arr[target]) {
            // Setting array as only first half
            return binaryFindElement(arr, first, target - 1, element);
        }
        else {
            // Setting array as only second half
            return binaryFindElement(arr, target + 1, last, element);
        }
    }
    else {
        // Failed to find key
        cout << "Did not find element\n";
        return -1;
    }
}