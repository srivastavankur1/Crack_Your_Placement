Node* constructTreeUtil(int& index, int n, int pre[], char preLN[]) {
    // Base case: If the index is out of bounds
    if (index == n)
        return NULL;

    // Allocate memory for the current node and set its value
    Node* node = new Node(pre[index]);

    // If the current node is a leaf node, return it
    if (preLN[index] == 'L') {
        index++;
        return node;
    }

    // If the current node is not a leaf node, set its left and right children
    index++;
    node->left = constructTreeUtil(index, n, pre, preLN);
    node->right = constructTreeUtil(index, n, pre, preLN);

    return node;
}

// The main function to construct the tree
Node* constructTree(int n, int pre[], char preLN[]) {
    int index = 0;  // Initialize index to keep track of the current node in pre[]
    return constructTreeUtil(index, n, pre, preLN);
}
