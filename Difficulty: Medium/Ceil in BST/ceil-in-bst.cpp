/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

int findCeil(Node* root, int input) {
    int ceil = -1;
    while (root) {
        if (root->data == input) {
            return root->data;  
        }
        if (input < root->data) {
            ceil = root->data;  
            root = root->left;  
        } else {
            root = root->right; 
        }
    }
    return ceil;
}
