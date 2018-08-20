// P1 - Write a function to display the contents of a binary
// tree, in sorted order. Then write one that displays them
// in reverse

// P2 - Write a function that counts the number of nodes in
// a binary tree

// P3 - Write a function to check if a binary tree is properly
// balanced

# include <iostream>

using namespace std;

struct node {
    int key;
    node *left;
    node *right;
};

// Function prototypes
node* insert(node *p_tree, int value);
void displaySorted(node *p_tree);
void displayReversed(node *p_tree);
int countNodes(node *p_tree, int count=0);
int balanced(node *p_tree, int head_val, int count=0);

// Main function call
int main()
{
    // Setting first (top) node of tree to NULL
    node *p_tree = NULL;

    // Setting default values for sake of exercise
    // (focus is not on building a tree but rather
    // traversing it)
    p_tree = insert(p_tree, 10);
    p_tree = insert(p_tree, 6);
    p_tree = insert(p_tree, 14);
    p_tree = insert(p_tree, 5);
    p_tree = insert(p_tree, 8);
    p_tree = insert(p_tree, 11);
    p_tree = insert(p_tree, 18);

    // cout << p_tree->left->right->key << endl;

    // Lets print out the values in sorted order:
    cout << "Printing tree nodes in sorted order...\n";

    displaySorted(p_tree);

    cout << "Printing tree nodes in reverse order...\n";

    displayReversed(p_tree);

    // int count = 0;

    cout << "Number of nodes in this binary tree is: "
         << countNodes(p_tree) << endl;

    cout << "Is the tree balanced?\n";

    if (balanced(p_tree, p_tree->key) == 1) {
        cout << "Yes!\n";
    }
    else {
        cout << "No\n";
    }

    return 0;

}



// Function Defined:

node* insert(node *p_tree, int value) {
    if (p_tree == NULL) {
        node *p_new_tree = new node;
        p_new_tree->key = value;
        // Don't forget to update both left & right pointers!
        p_new_tree->left = NULL;
        p_new_tree->right = NULL;
        return p_new_tree;
    }
    else if (value < p_tree->key) {
        p_tree->left = insert(p_tree->left, value);
    }
    else {
        p_tree->right = insert(p_tree->right, value);
    }
    // Returning full tree with added node
    return p_tree;
}


void displaySorted(node *p_tree) {
    // 1st Base Case, just check if main tree is NULL
    if (p_tree == NULL) {
        return;
    }

    // Real Base Case, if no node to the left, that makes
    // current node smallest in tree:
    if (p_tree->left == NULL) {
        // Print out node value
        cout << p_tree->key << endl;
        
        // Check to see if there is a right node:
        if (p_tree->right == NULL) {
            // Nothing there? Return empty
            return;
        }
        else {
            // If there is something there, we want to
            // call the function on the right subtree,
            // and go through the same process:
            displaySorted(p_tree->right);
        }
    }
    else {
        // call function on left subtree:
        displaySorted(p_tree->left);

        // Once all of its smaller nodes have been printed,
        // print out the current node!
        cout << p_tree->key << endl;
    }
    if (p_tree->right == NULL) {
        // Nothing there? Return empty
        return;
    }
    else {
        displaySorted(p_tree->right);
    }
}


void displayReversed(node *p_tree) {
    // p_tree NULL base case
    if (p_tree == NULL) {
        return;
    }

    // Check to see if right subtree is NULL. If so,
    // this is the greatest value in the tree, so print it:
    if (p_tree->right == NULL) {
        cout << p_tree->key << endl;

        // Now we need to check for its smaller values, which
        // would still be bigger than the rest of the tree (not
        // under the current node)
        if (p_tree->left == NULL) {
            // If nothing smaller, than we're fine. Return:
            return;
        }
        else {
            // We need to check for values in the left subtree, so
            // we "repeat" our initial search and print process there:
            displayReversed(p_tree->left);
        }
    }
    // Not NULL? We need to keep checking right subtrees
    else {
        displayReversed(p_tree->right);
        // After right subtree has been checked, we can print out
        // the current node (since all values in its right subtree are
        // bigger than itself):
        cout << p_tree->key << endl;

        // Now go through its left subtree, if it is there, and
        // repeat the process
        displayReversed(p_tree->left);
    }

}


int countNodes(node *p_tree, int count) {
    // To count our nodes, we can traverse our tree
    // in a paritcular order (such as sorted order,
    // which is what we will do), and keep a count of the
    // nodes in ascending order, just like if we were to 
    // print them sorted:

    // Note that we pass in a count as a function argument,
    // because we want to carry over the count value into
    // each recursive call, instead of having it initiazlied
    // to 0 at the beginning of every function call.

    // If tree is NULL, just return count (which would be 0)
    if (p_tree == NULL) {
        return count;
    }

    // Base case, we found the smallest node:
    if (p_tree->left == NULL) {
        count++;

        // Check for a right subtree and any larger values
        // (but not larger than the parent node) to add to
        // the count
        if (p_tree->right == NULL) {
            return count;
        }
        // Repeating process for right subtree (if there)
        else {
            count = countNodes(p_tree->right, count);
        }
    }
    else {
        // If there is a left subtree, look there for lower
        // values and set count equal to all the counts we
        // tally up there
        count = countNodes(p_tree->left, count);

        // Now we can tally the current node, that we've checked
        // all the ones below it:
        count++;
    }
    // Now to check the current node's right subtree, and repeat
    // the process there:
    if (p_tree->right == NULL) {
        return count;
    }
    else {
        count = countNodes(p_tree->right, count);
    }
    return count;
}


int balanced(node *p_tree, int head_val, int count) {
    // Similiar to countNodes, we will be counting nodes in
    // ascending order. While on the left side of the passed
    // in tree, we will -1 count, and +1 to
    // count once we are on the right side of the tree, or hit the head
    // node.
    // A balanced tree should return 1, with both sides cancelling
    // each other out, excluding the head node which returns +1.
    
    // For a sorted tree (which is the assumption of this
    // exercise), it's easy to know when to tally the count
    // on the right side. If the value of the current node is
    // less than value of the head node, its on the left. Greater
    // or equal to? Than its on the right.

    // NOTE* In the end, count should return 1 if balanced, since
    // we know that we will be including the head_node with our check
    // (greater than or equal to will eventually return true for the
    // head node)

    // Like countNodes, we will keep track of our count variable,
    // and also a constant value for the head node, since the value of
    // p_tree will be dependent on wether its a recursive call or not:

    // Checking if NULL
    if (p_tree == NULL) {
        // Return false because there is no tree?
        return count;
    }

    // Going for lowest value:
    if (p_tree->left == NULL) {
        // Smallest one, lets keep count!
        if (p_tree->key < head_val) {
            count--;
        }
        else {
            count++;
        }

        // Now to check if this smallest val has a right
        // subtree
        if (p_tree->right == NULL) {
            // No right subtree, return count
            return count;
        }
        // If so, continue our counting search there:
        else {
            count = balanced(p_tree->right, head_val, count);
        }
    }
    else {
        // If there is a left node, continue our counting
        // search there:
        count = balanced(p_tree->left, head_val, count);

        // Now that all children left subtree nodes are counted,
        // we need to count the current node:
        if (p_tree->key < head_val) {
            count--;
        }
        else {
            count++;
        }

        // Now to check the current node's right subtree, if it
        // exists:
        if (p_tree->right == NULL) {
            // No right subtree, return count
            return count;
        }
        else {
            // Contitnue our counting search in the right
            // subtree
            count = balanced(p_tree->right, head_val, count);
        }
    }
    // We return the count value for the current call. For the main
    // function call on the passed in tree (so not a recursive call),
    // count should return 1 for a balanced tree
    return count;
}