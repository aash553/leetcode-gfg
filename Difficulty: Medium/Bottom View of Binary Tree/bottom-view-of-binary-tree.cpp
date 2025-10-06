/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int>bottom;
        if(root == NULL) return bottom;
        map<int,int>mpp; // vertical , node val
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node * node = it.first;
            int line = it.second;
            mpp[line] = node -> data;
            
            if(node -> left != NULL) q.push({node->left , line-1});
            if(node ->right != NULL) q.push({node->right , line+1});
        }
        for(auto it : mpp){
            bottom.push_back(it.second);
        }
        return bottom;
    }
};