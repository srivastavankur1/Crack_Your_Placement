// Function to count nodes in a BST
int countNodes(Node* root) {
    if (root == NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

// Function to find the k-th node in an in-order traversal
void findKthNode(Node* root, int& k, Node*& result) {
    if (root == NULL || result != NULL)
        return;
    
    // Traverse left subtree
    findKthNode(root->left, k, result);
    
    // Decrement k and check if k is 0 (indicating current node is the k-th node)
    k--;
    if (k == 0) {
        result = root;
        return;
    }
    
    // Traverse right subtree
    findKthNode(root->right, k, result);
}

// Function to find the median of the BST
float findMedian(struct Node* root) {
    if (root == NULL)
        return 0.0;
    
    int n = countNodes(root);
    Node* first = NULL;
    Node* second = NULL;
    
    if (n % 2 == 1) {  // Odd number of nodes
        int k = n / 2 + 1;
        findKthNode(root, k, first);
        return (float)(first->data);
    } else {  // Even number of nodes
        int k1 = n / 2;
        int k2 = k1 + 1;
        findKthNode(root, k1, first);
        findKthNode(root, k2, second);
        return (float)(first->data + second->data) / 2.0;
    }
}
