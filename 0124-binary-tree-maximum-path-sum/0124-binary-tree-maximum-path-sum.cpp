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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxisum(root,maxi);
        return maxi;
    }


    int maxisum(TreeNode * node , int &maxi){
        if(!node) return 0;

        int left = max(0,maxisum(node->left,maxi));
        int right = max(0,maxisum(node->right,maxi));
        maxi = max(node->val+left+right,maxi);
        return (node->val) + max(left,right); 
    }



};