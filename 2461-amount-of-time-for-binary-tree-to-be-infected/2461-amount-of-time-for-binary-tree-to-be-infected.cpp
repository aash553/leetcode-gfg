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

    TreeNode * mark(TreeNode * root , unordered_map<TreeNode* , TreeNode*>&parent_track , int start){
        queue<TreeNode*>q;
        TreeNode * res;
        q.push(root);
        while(!q.empty()){
            TreeNode * node = q.front();
            q.pop();
            if(node->val == start) res = node;

            if(node->left){
                parent_track[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent_track[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }

    int maxi ( unordered_map<TreeNode*,TreeNode*> & parent_track , TreeNode * target){
        queue<TreeNode*>q;
        q.push(target);
        unordered_map<TreeNode*, bool>vis;
        vis[target] = true;
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            int flag = 0 ;
            for(int i = 0 ; i <size;i++){
            TreeNode * node = q.front();
            q.pop();
            if(node->left && !vis[node->left]){
                flag = 1;
                q.push(node->left);
                vis[node->left] = true;
            }
            if(node->right && !vis[node->right]){
                flag = 1;
                q.push(node->right);
                vis[node->right] = true;
            }
            if(parent_track[node] && !vis[parent_track[node]]){
                flag = 1;
                q.push(parent_track[node]);
                vis[parent_track[node]]= true;
            }
            }
            if(flag)time++;
        }
        return time;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode* , TreeNode* > parent_track;
        TreeNode * target = mark(root,parent_track,start);
        return maxi(parent_track,target);
    }
};