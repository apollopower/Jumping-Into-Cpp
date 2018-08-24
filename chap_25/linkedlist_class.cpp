class Node
{
    public:
        ~Node();
        int val;
        Node *p_next;
}

class LinkedList
{
    public:

        LinkedList(); // Constructor
        ~LinkedList(); // Destructor, notice the tilde (~)
        // Operator: to copy functions
        LinkedList& operator= (const LinkedList &other);
        // copy constructor
        LinkedList(const LinkedList &other) 

        void insert(int val); // adds a node
    
    private:

        Node *_p_head;
};

// Node deconstructor
Node::~Node()
{
    delete p_next; // This ACTUALLY works (keeps deleting p_next
                    // until it reached NULL)
}

// With the above destrucot for nodes, we just need to write it
// for the head:

LinkedList::~LinkedList()
{
    delete _p_head;
}

// Destructors are important for:
// 1) When you delete a pointer to an object
// 2) When the object goes out of scope (like in a function)
// 3) When the object belongs to a class whose destructor is being called

LinkedList& LinkedList::operator= (const LinkedList &other)
{
    // Make sure we aren't assigning to ourself --  we can just ignore
    // that if it happens. Notice that we're using 'this' here to
    // ensure that the other value isn't the same address as our
    // object:
    if (this == & other) {
        // return this object to keep chain of object alive
        return *this;
    }
    // before copying over the new values, we need to free
    // the old memory, since it's no longer used:
    delete _p_head;
    _p_head = NULL;

    LinkedList *p_itr = other._p_head;
    while (p_itr != NULL) {
        insert(p_itr->val);
    }
    return *this;
}

// Copying with the operator makes copying classes we built much safer
// For example, it allows us to do chain assignments:
// linked_list = rhs = lhs;

