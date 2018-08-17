// Write a program to remove an element from a linked list; the
// remove function should take just the element to be removed.

// WARNING: Not complete yet.

# include <iostream>

using namespace std;

struct LinkedList {
    int number;
    LinkedList* p_next_element;
};

// Globally setting head of linked list
LinkedList* p_list = NULL;

LinkedList* buildLinkedList(LinkedList* p_list, int num) {
    LinkedList* p_element = new LinkedList;
    p_element->number = num;
     p_element->p_next_element = p_list;
    return p_element;
}

void removeElement(int element) {
    LinkedList* p_current = p_list;
    LinkedList* p_prev = NULL;

    if (p_list->number == element) {
        LinkedList* p_temp = p_list->p_next_element;

        delete p_list;
        p_list = p_temp;
        return;
    }

    while (p_current->number != element) {
        p_prev = p_current;
        p_current = p_current->p_next_element;
    }

    p_prev->p_next_element = p_current->p_next_element;
    delete p_current;

}

int main() {
    int length;
    int element;

    cout << "Please input a length for linked list: ";
    cin >> length;
    for (int i = 0; i < length; i++) {
        p_list = buildLinkedList(p_list, i);
    }

    cout << "Printing values of current linked list: \n";

    LinkedList* p_current = p_list;
    while (p_current != NULL) {
        cout << p_current->number << endl;
        p_current = p_current->p_next_element;
    }

    // Removing an element:
    cout << "Choose a number from above to remove from the linked list: ";
    cin >> element;

    removeElement(element);

    cout << "Printing values of current linked list: \n";

    p_current = p_list;
    while (p_current != NULL) {
        cout << p_current->number << endl;
        p_current = p_current->p_next_element;
    }

    delete p_current;
    delete p_list;

    return 0;
}