// Write a recursive function that takes an array and displays
// the elements in reverse order WITHOUT starting the index of
// the array at the end.

# include <iostream>

using namespace std;

int reversePrint(int arr[], int idx_at_size) {
    if (idx_at_size == 0) {
        cout << arr[idx_at_size] << endl;
        return arr[idx_at_size];
    }

    cout << arr[idx_at_size] << endl;
    reversePrint(arr, idx_at_size - 1);
    return arr[idx_at_size];
}

int main() {
    int size;

    cout << "How big do you want the array? ";
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
        cout << arr[i] << endl;
    }

    cout << "Reverse printing...\n";

    int idx_at_size = size - 1;

    reversePrint(arr, idx_at_size);
}