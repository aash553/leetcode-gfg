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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL) return ans;
        map<int,map<int,multiset<int>>>mpp; // verticals , level , nodes 
        queue<pair<TreeNode * , pair<int,int>>>q; // nodes,verticals,level
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it = q.front();
            TreeNode * node = it.first;
            q.pop();
            int x = it.second.first;
            int y = it.second.second;
            mpp[x][y].insert(node->val);

            if(node->left != NULL) q.push({node->left ,{x-1,y+1}});
            if(node->right != NULL) q.push({node->right , {x+1, y+1}});
        }
        for(auto p : mpp){
            vector<int>cols;
            for(auto it : p.second){
                cols.insert(cols.end(),it.second.begin(),it.second.end());
            }
            ans.push_back(cols);
        }
        return ans;
    }
};