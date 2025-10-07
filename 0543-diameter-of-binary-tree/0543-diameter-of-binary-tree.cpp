/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int height (TreeNode * root , int &diameter){
        TreeNode * node = root;
        if(root == NULL) return 0;
        
        int left = height(node->left,diameter);
        int right = height(node->right,diameter);
        diameter = max(left+right , diameter);
        return 1 + max(right , left);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root,diameter);
        return diameter;
    }
};