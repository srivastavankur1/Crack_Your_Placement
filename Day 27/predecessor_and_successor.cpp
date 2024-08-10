void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    pre = NULL;
    suc = NULL;
    Node* current = root;
    while (current) {
        if (current->key == key) {
            // For predecessor
            if (current->left) {
                Node* temp = current->left;
                while (temp->right)
                    temp = temp->right;
                pre = temp;
            }
            // For successor
            if (current->right) {
                Node* temp = current->right;
                while (temp->left)
                    temp = temp->left;
                suc = temp;
            }
            return;
        }
        else if (current->key > key) {
            suc = current;
            current = current->left;
        }
        else { // current->key < key
            pre = current;
            current = current->right;
        }
    }
}
