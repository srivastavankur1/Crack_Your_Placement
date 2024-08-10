class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* mergeTwoLists(Node* a, Node* b) {
        // Base cases
        if (!a) return b;
        if (!b) return a;
        
        // Compare the data members and recursively merge
        Node* result;
        if (a->data < b->data) {
            result = a;
            result->bottom = mergeTwoLists(a->bottom, b);
        } else {
            result = b;
            result->bottom = mergeTwoLists(a, b->bottom);
        }
        return result;
    }
    
    Node* flatten(Node* root) {
        // Base case
        if (!root || !root->next) {
            return root;
        }
        
        // Recursively flatten the next list
        root->next = flatten(root->next);
        
        // Merge this list with the flattened list from the next node
        root = mergeTwoLists(root, root->next);
        
        return root;
    }
};