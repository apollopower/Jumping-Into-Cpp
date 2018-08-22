#include <iostream>
#include "linkedlist.h"
#include "newheader.h"

// using namespace std;

int main()
{
    Node *p_list = NULL;

    for (int i = 0; i < 10; ++i) {
        p_list = addNode(p_list, i);
    }

    printList(p_list);
}
