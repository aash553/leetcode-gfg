/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void mark(TreeNode * root , TreeNode * target , unordered_map<TreeNode* , TreeNode*> & parent_track){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
                TreeNode * node = q.front();
                q.pop();
                if(node->left){
                    parent_track[node->left] = node;
                    q.push(node->left); 
                }
                if(node->right){
                    parent_track[node->right] = node;
                    q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> parent_track;
        mark(root, target , parent_track);

        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>vis;
        q.push(target);
        vis[target] = true; 
        int cur_level = 0;
        while(!q.empty()){
            int size = q.size();
            if(cur_level ++ == k) break;
            for(int i = 0;i<size;i++){
                TreeNode * node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right] = true;
                }

                if(parent_track[node] && !vis[parent_track[node]]){
                    q.push(parent_track[node]);
                    vis[parent_track[node]]= true;
                }
            }
        }
        vector<int>res;
        while(!q.empty()){
            TreeNode * node = q.front();
            q.pop();
            res.push_back(node->val);
        }
        return res;
    }
};