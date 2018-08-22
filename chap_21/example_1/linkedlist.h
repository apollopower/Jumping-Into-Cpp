#ifndef LINKED_H
#define LINKED_H

struct Node {
    int value;
    Node *p_next;
};

Node* addNode(Node* p_list, int value);
void printList(const Node* p_list);

#endif