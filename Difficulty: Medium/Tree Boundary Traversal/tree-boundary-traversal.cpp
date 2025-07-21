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
  
  bool isLeaf(Node* node) {
    return (node->left == NULL && node->right == NULL);
}

  
  void leftboundary(Node * root ,  vector<int>&res){
      Node * curr = root->left;
      while(curr){
          if(!isLeaf(curr))res.push_back(curr->data);
          //i will move to left 
          if(curr->left) curr = curr->left;
          else curr= curr->right;
      }
  }
  
 void rightboundary (Node * root ,  vector<int>&res){
     Node * cur = root ->right;
     vector<int>temp;
     while(cur){
     if(!isLeaf(cur)) temp.push_back(cur->data);
     if(cur->right) cur = cur->right;
     else cur=cur->left;
     }
     for(int i = temp.size()-1 ; i>=0;i--){
         res.push_back(temp[i]);
     }
 }
 
 
 void addleaves(Node * root ,  vector<int>&res){
     if(isLeaf(root)){
         res.push_back(root->data);
         return;
     }
     
     if(root->left) addleaves(root->left,res);
     if(root->right) addleaves(root->right,res);
 }
 
  
  
    vector<int> boundaryTraversal(Node *root) {
        vector<int>res;
        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        leftboundary(root,res);
        addleaves(root,res);
        rightboundary(root,res);
        return res;
    }
};