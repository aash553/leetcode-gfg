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

    TreeNode * prev= NULL;
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL) return INT_MAX;
        int ans = INT_MAX;

        //inorder traversal

        if(root->left ){
            int leftmin = getMinimumDifference(root->left);
            ans = min(ans,leftmin);
        }

        //root
        if(prev != NULL){
            ans = min(ans, root->val - prev->val);
        }
        prev = root;

        //right
        if(root->right){
            int rightmin = getMinimumDifference(root->right);
                ans = min(ans,rightmin);
        }
        return ans;
    }
};