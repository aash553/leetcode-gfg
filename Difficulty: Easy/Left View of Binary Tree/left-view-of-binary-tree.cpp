/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
       vector<int>left;
       queue<Node*> q;
       if(root == NULL) return left;
       q.push(root);
       while(!q.empty()){
           int size = q.size();
           for(int i = 0 ; i<size ; i++){
               Node * node = q.front();
               q.pop();
               if(i == 0) left.push_back(node -> data);
               
               if(node->left != NULL) q.push(node->left);
               if(node->right != NULL) q.push(node->right);
           }
       }
       return left;
    }
};