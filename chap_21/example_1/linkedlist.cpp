#include <iostream>
#include "linkedlist.h"

using namespace std;

Node* addNode(Node* p_list, int value) {
    Node *p_new_node = new Node;
    p_new_node->value = value;
    p_new_node->p_next = p_list;
    return p_new_node;
}

void printList(const Node* p_list) {
    const Node *p_current = p_list;
    while (p_current != NULL) {
        cout << p_current->value << endl;
        p_current = p_current->p_next;
    }
}