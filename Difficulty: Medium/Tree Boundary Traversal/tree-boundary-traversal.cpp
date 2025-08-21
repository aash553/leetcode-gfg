/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
  bool isleaf(Node * root){
      return (root->left == NULL && root->right == NULL);
  }
  
  void leftbound(Node * root , vector<int>&res){
    Node * cur = root->left;
    while(cur){
        if(!isleaf(cur)) res.push_back(cur->data);
        if(cur->left!=NULL) cur = cur->left;
        else cur = cur->right;
    }
  }
  
  void addleaf(Node * root , vector<int>&res){
      while(isleaf(root)){
          res.push_back(root->data);
          return;
      }
      if(root->left) addleaf(root->left,res);
      if(root->right) addleaf(root->right,res);
  }
  
  void rightbound(Node * root, vector<int>&res){
      Node * cur = root->right;
      vector<int>temp;
      while(cur){
          if(!isleaf(cur))temp.push_back(cur->data);
          if(cur->right!=NULL) cur = cur->right;
          else cur = cur->left;
      }
      for(int i = temp.size()-1;i>=0;i--){
          res.push_back(temp[i]);
  }
  }
  
    vector<int> boundaryTraversal(Node *root) {
        vector<int>res;
        if(!root) return res;
        if(!isleaf(root)) res.push_back(root->data);
        leftbound(root,res);
        addleaf(root,res);
        rightbound(root,res);
        return res;
    }
};