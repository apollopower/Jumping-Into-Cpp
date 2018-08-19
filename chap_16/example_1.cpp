// using recursion to traverse a linked list and 
// return a desired value's address:

# include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
};

// Globar Var pointing to head of LinkedList:
Node* head = NULL;

Node* addNode(Node* head, int num) {
    Node* element = new Node;
    element->value = num;
    element->next = head;
    return element;
}

void printList(Node* list) {
    if (list == NULL) {
        return;
    }
    printList(list->next);
    cout << list->value << " located at: " << list << endl;
}

// Note use of recurive call to run search on next list element
Node* search_for(Node* list, int value_to_find) {
    if (list == NULL) {
        return NULL;
    }
    else if (list->value == value_to_find) {
        return list;
    }
    else {
        return search_for(list->next, value_to_find);
    }
}

int main() {
    int length;
    int value_to_find;

    cout << "Please enter a length for the linked list: ";
    cin >> length;
    cout << "Making Linked List...\n";
    for (int i = 0; i < length; i++) {
        head = addNode(head, i);
    }
    cout << "Printing Linked List Values...\n";
    printList(head);

    cout << "which value are you looking for? ";
    cin >> value_to_find;

    cout << search_for(head, value_to_find) << endl;

    // Getting rid of allocated memory
    delete head;

    return 0;
    
}