// Binary Tree
// An implementation of a Binary tree along with creating, adding
// nodes, travsersing the tree deleting nodes, and deleting the tree

# import <iostream>

using namespace std;

struct Node {
    int key_value;
    Node *p_left;
    Node *p_right;
};

// Our function prototypes
Node* insert(Node *p_tree, int key);
Node* search(Node *p_tree, int key);
Node* remove(Node *p_tree, int key);
Node* findMax(Node *p_tree);
Node* removeMaxNode(Node *p_tree, Node *p_max_node);
void destroyTree(Node *p_tree);

// Our main function call:
int main() 
{
    Node* p_tree = NULL;
    int build_status = 1;
    int provided_value = 0;

    while (provided_value != -1) {
        cout << "Specify a value to insert into the tree. -1 to stop: \n";
        if (provided_value != -1) {
            cin >> provided_value;
            p_tree = insert(p_tree, provided_value);
        }
    }

    cout << "What value would you like to look for? ";
    int desired_value;
    cin >> desired_value;

    cout << search(p_tree, desired_value) << endl;

    cout << "What value in the tree would you like to delete? ";
    int desired_delete_value;
    cin >> desired_delete_value;

    cout << remove(p_tree, desired_delete_value) << endl;

    cout << "Deleting the entire tree!\n";

    destroyTree(p_tree);
    p_tree = NULL;

}

// Here are all our function defined:

Node* insert(Node *p_tree, int key) {
    // Base Case:
    // If p_tree is NULL, we can insert the value
    if (p_tree == NULL) {
        // Initializing new node
        Node *p_new_tree = new Node;
        // Setting values:
        p_new_tree->key_value = key;
        p_new_tree->p_left = NULL;
        p_new_tree->p_right = NULL;
        return p_new_tree;
    }
    
    else if (key < p_tree->key_value) {
        // We are NOT re-writing p_tree (like we would in a
        // linked list). Instead, we call the insert funcion 
        // on the respective pointer and set the tree's pointer
        // set to the return value
        p_tree->p_left = insert(p_tree->p_left, key);
    }
    else {
        p_tree->p_right = insert(p_tree->p_right, key);
    }
    // After key inserted, return the tree!
    return p_tree;
}

Node* search(Node *p_tree, int key) {
    // Base Case 1:
    // We didn't find the value in the first place!
    if (p_tree == NULL) {
        return NULL;
    }
    // Base Case 2:
    // If value of p_tree is the one we want, return it
    else if (key == p_tree->key_value) {
        return p_tree;
    }
    // Our recursive calls, depending on the key's value
    else if (key < p_tree->key_value) {
        return search(p_tree->p_left, key);
    }
    else {
        return search(p_tree->p_right, key);
    }

}

Node* findMax(Node *p_tree) {
    if (p_tree == NULL) {
        // Found nothing
        return NULL;
    }
    else if (p_tree->p_right == NULL) {
        // Found largest value in tree
        return p_tree;
    }
    else {
        return findMax(p_tree->p_right);
    }
}

Node* removeMaxNode(Node *p_tree, Node *p_max_node) {
    // Defensive programming; shouldn't actually hit this:
    if (p_tree == NULL) {
        return NULL;
    }
    // Since we found the node, we can now replace it:
    if (p_tree == p_max_node) {

        // The only reason that we can do this is because weß
        // know p_max_node->p_right is NULL (since p_max_node is
        // is the MAX VALUE) so we aren't losing any information.
        // So we return the pointer to p_max_node->p_left, which may
        // or may not be NULL. If there is a left subtree, we need
        // to modify the parent of the max node to point to the left
        // subtree. If the result is NULL, p_max_node will be replaced
        // with an empty node, which is what we want.
        return p_max_node->p_left;
    }
    // Each recursive call replaces the right subtree tree with
    // a new subtree that does not contain p_max_node
    p_tree->p_right = removeMaxNode(p_tree->p_right, p_max_node);
    
    // NOTE: The final function returns the original tree passed into
    // it (in this specific use case, the left subtree), even if the
    // max_node was not the head of the passed in tree. SO it returns
    // the passed in tree with the max_node removes and the max_nodes's
    // left subtree connected to the max_node's original parent node.
}

Node* remove(Node *p_tree, int key) {
    if (p_tree == NULL) {
        return NULL;
    }
    else if (p_tree->key_value == key) {
        // Find the greatest value stored on one side
        // of the tree, and promote it to the top of
        // the tree

        // The first two cases handle having zero or
        // one child node
        if (p_tree->p_left == NULL) {
            Node *p_right_subtree = p_tree->p_right;
            delete p_tree;
            // Note this might return NULL if there are
            // zero child nodes, but that is what we want anyway
            return p_right_subtree;
        }
        else if (p_tree->p_right == NULL) {
            Node *p_left_subtree = p_tree->p_left;
            delete p_tree;
            // This will always return a valid node, since we
            // know p_tree->p_left is not NULL from the previous
            // if statement
            return p_left_subtree;
        }
        // After the recursive calls are finished, meaning that
        // we now have a new value for p_tree(either it's left or
        // right subtree), we find the max value of that subtree
        // making it the top node where we are doing the removal.
        // We then set the new top node to point to the removed
        // nodes left and right nodes.
        Node *p_max_node = findMax(p_tree->p_left);
        // Since p_max_node came from the left subtree, we need
        // to remove it from the that subtree before re-linking
        // that subtree back into the rest of the tree:
        p_max_node->p_left = removeMaxNode(
                                p_tree->p_left,
                                p_max_node
                             );
        p_max_node->p_right = p_tree->p_right;
        delete p_tree;
        return p_max_node;
    }
    else if (key < p_tree->key_value) {
        p_tree->p_left =  remove(p_tree->p_left, key);
    }
    else {
        p_tree->p_right = remove(p_tree->p_right, key);
    }
    return p_tree;
}

void destroyTree(Node *p_tree) {
    if (p_tree != NULL) {
        // Notice that the tree is delete from "bottom-up"
        destroyTree(p_tree->p_left);
        destroyTree(p_tree->p_right);
        delete p_tree;
        // The recursive call goes all the way to the lowest subtree
        // which is not NULL, and then deletes it. From there, the
        // recursive calls take over and come back each level,
        // destroying each subtree above it
    }
}