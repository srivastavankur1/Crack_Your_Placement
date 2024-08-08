class Solution{
public:
    int getCount(Node *root, int l, int h)
    {
        if (root == nullptr) {
            return 0;
        }
    
        // If the current node's value is within the range [l, h]
        if (root->data >= l && root->data <= h) {
            // Count this node and proceed to both left and right children
            return 1 + getCount(root->left, l, h) + getCount(root->right, l, h);
        }
    
        // If the current node's value is less than l, only explore the right subtree
        else if (root->data < l) {
            return getCount(root->right, l, h);
        }
    
        // If the current node's value is greater than h, only explore the left subtree
        else {
            return getCount(root->left, l, h);
        }  
    }
};