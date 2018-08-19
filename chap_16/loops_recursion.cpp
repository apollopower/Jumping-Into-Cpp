// Here we compare loops vs recursion by having both implementations
// of traversing a linked list:

# include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
};

// Creating head of linked list:
Node* head = NULL;

Node* addNode(int num) {
    Node* element = new Node;
    element->value = num;
    element->next = head;
    return element;
}

// Recursive approach to traverse list for value:
Node *recursive_search_for(Node *head, int value_to_find) {
    if (head == NULL) {
        // Base case if value does not exist
        return NULL;
    }
    else if (head->value == value_to_find) {
        // Base case if value DOES exist
        return head;
    }
    else {
        return recursive_search_for(head->next, value_to_find);
    }
}

// Iterative Approach:
Node *iterative_search_for(Node *head, int value_to_find) {
    // An "infinitely true loop"
    while (1) {
        if (head == NULL) {
            // If we dont find the value, this will stop the loop
            // and return NULL
            return NULL;
        }
        else if (head->value == value_to_find) {
            return head;
        }
        else {
            head = head->next;
        }
    }
}

// Now lets call them in our main function
int main() {
    int length;
    int value_to_find;

    cout << "Please specify length of linked list: ";
    cin >> length;

    for (int i = 0; i < length; i++) {
        cout << "Adding node with value of " << i << endl;
        head = addNode(i);
    }

    cout << "What value would you like to look for? ";
    cin >> value_to_find;

    // Recursive search
    cout << "Looking for it recursively...\n";
    cout << recursive_search_for(head, value_to_find) << endl;

    // Iterative search
    cout << "Looking for it iteratively...\n";
    cout << iterative_search_for(head, value_to_find) << endl;
}