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

    void mark(TreeNode* root,unordered_map<TreeNode* ,TreeNode*> &parent_track, TreeNode * target){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            TreeNode * current = q.front();
            q.pop();
            if(current->left){
                parent_track[current->left] =current;
                q.push(current->left);
            }
            if(current->right){
                parent_track[current->right] = current; 
                q.push(current->right);
            }
        }
    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* ,TreeNode*> parent_track;
        mark(root,parent_track,target);

        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int curr_level=0;
        while(!q.empty()){
            int size = q.size();
            if(curr_level ++ == k) break;
            for(int i =0;i<size;i++){
                TreeNode * current = q.front();
                q.pop();
                if(current->left && !vis[current->left]){
                    q.push(current->left);
                    vis[current->left] = true;
                }

                if(current->right && !vis[current->right]){
                    q.push(current->right);
                    vis[current->right] = true;
                }
                if(parent_track[current] && !vis[parent_track[current]]){
                    q.push(parent_track[current]);
                    vis[parent_track[current]] = true;
                }
            }
        }
        vector<int>result;
        while(!q.empty()){
            TreeNode * current = q.front();
            q.pop();
            result.push_back(current->val);
        }
        return result;
    }
};