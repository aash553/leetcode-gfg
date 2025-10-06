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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>post;
        stack<TreeNode*>st;
        if(root == NULL) return post;
        st.push(root);
        while(!st.empty()){
            TreeNode * node = st.top();
            st.pop();
            post.push_back(node->val);
            if(node->left != NULL) st.push(node->left);
            if(node->right != NULL) st.push(node->right);
        }
        reverse(post.begin(),post.end());
        return post;
    }
};