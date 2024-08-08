class Solution
{
    public: 
    void bToDLLUtil(Node* root, Node** head, Node** prev) {
        if (root == nullptr) return;
    
        // Recursively convert the left subtree
        bToDLLUtil(root->left, head, prev);
    
        // If this is the leftmost node, it becomes the head of the DLL
        if (*prev == nullptr) {
            *head = root;
        } else {
            // Link the current node with the previous node in DLL
            root->left = *prev;
            (*prev)->right = root;
        }
    
        // Update the previous node to the current node
        *prev = root;
    
        // Recursively convert the right subtree
        bToDLLUtil(root->right, head, prev);
    }
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        if (root == nullptr) return nullptr;
    
        Node* head = nullptr;  // Head of the doubly linked list
        Node* prev = nullptr;  // Previous node in DLL
    
        // Convert the binary tree to DLL using in-order traversal
        bToDLLUtil(root, &head, &prev);
    
        return head;
    }
};
