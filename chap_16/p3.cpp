// Write a recursive algorithm to remove elements from a linked list.
// Write one also to add elements into a linked list.
// Then write the same algorithms using iteration.

# include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
};

// ****************************************
// Creating global variable for linked list
Node* head = NULL;
// ****************************************

Node *addNode(int number);
void recursiveRemoval();
void recursiveAddition(int length);
void iterativeRemoval();
void iterativeAddition(int length);

// Main function call
int main() 
{

    int first_size;
    int second_size;

    cout << "Specify legnth of linked list: ";
    cin >> first_size;

    // Creating first linked_list (standard loop)
    for (int i =0; i < first_size; i++) {
        head = addNode(i);
        cout << head->value << endl;
    }

    cout << "Removing nodes...\n";

    recursiveRemoval();

    cout << "Last remaining node = " << head->value << endl;

    cout << "How many numbers do you want to add to the linked list? ";
    cin >> second_size;

    cout << "Adding nodes...\n";

    recursiveAddition(second_size);

    cout << "last added node = " << head->value << endl;

    cout << "Repeating the removal and addition process iteratively..\n";

    iterativeRemoval();

    cout << "Last remaining node = " << head->value << endl; // should be 0

    iterativeAddition(second_size);

    cout << "Last added node = " << head->value << endl; // should be 1

    delete head;

}

Node* addNode(int number) {
    Node* new_node = new Node;
    new_node->value = number;
    new_node->next = head;
    return new_node;
}

void recursiveRemoval() {
    if (head->next == NULL) {
        // Only first node should remain
        return;
    }
    Node* p_temp = head->next;
    delete head;
    head = p_temp;
    recursiveRemoval();
}

void recursiveAddition(int length) {
    if (length == 0) {
        // We have increased the size of linkedlist
        // by specified length
        return;
    }
    // Using length as arbitrary value to put in linked list:
    head = addNode(length);
    // Checking current value for element in linked list:
    cout << head->value << endl;
    // Recursive call
    recursiveAddition(length - 1);
}

void iterativeRemoval() {
    while (head->next != NULL) {
        Node* p_temp = head->next;
        delete head;
        head = p_temp;
    }
}

void iterativeAddition(int length) {
    while (length > 0) {
        head = addNode(length);
        cout << head->value << endl;
        length--;
    }
}