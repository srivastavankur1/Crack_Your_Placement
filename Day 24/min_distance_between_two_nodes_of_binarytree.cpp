Node* findLCA(Node* root, int a, int b) {
    if (root == nullptr || root->data == a || root->data == b) {
        return root;
    }
    
    Node* leftLCA = findLCA(root->left, a, b);
    Node* rightLCA = findLCA(root->right, a, b);
    
    if (leftLCA != nullptr && rightLCA != nullptr) {
        return root;
    }
    
    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

int findDistanceFromLCA(Node* root, int val, int dist) {
    if (root == nullptr) {
        return -1;
    }
    
    if (root->data == val) {
        return dist;
    }
    
    int leftDist = findDistanceFromLCA(root->left, val, dist + 1);
    if (leftDist != -1) {
        return leftDist;
    }
    
    return findDistanceFromLCA(root->right, val, dist + 1);
}