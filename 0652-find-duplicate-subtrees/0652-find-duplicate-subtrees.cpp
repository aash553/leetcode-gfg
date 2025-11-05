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

    string sealize(TreeNode*root , unordered_map<string,int>&mpp , vector<TreeNode*>&ans){
        if(!root) return "#";
        string str = to_string(root->val) + "," 
                    + sealize(root->left,mpp,ans) + ","
                    + sealize(root->right,mpp,ans);
        if(mpp[str]==1){
            ans.push_back(root);
        }
        mpp[str]++;
        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        unordered_map<string,int>mpp;
        sealize(root , mpp , ans);
        return ans;
    }
};