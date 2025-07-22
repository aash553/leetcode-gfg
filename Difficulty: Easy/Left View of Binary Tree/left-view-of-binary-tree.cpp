/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
  
  void recur(Node *root , int level , vector<int>&res){
      if(root == NULL ) return;
      
      if(res.size() == level ) res.push_back(root->data);
      recur(root->left , level+1, res);
      recur(root->right , level+1 , res);
  }
  
  
    vector<int> leftView(Node *root) {
        // code here
        vector<int>res;
        recur(root,0,res);
        return res;
    }
};