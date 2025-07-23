/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
  Node * mark(Node* root,unordered_map<Node* , Node*>&parent_track, int target){
      
      queue<Node*>q;
      q.push(root);
      Node * res;
      while(!q.empty()){
          Node * node = q.front();
          if(node->data == target) res = node;
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
      return res;
  }
  
  
  int maxi(unordered_map<Node* , Node*>&parent_track, Node * target){
      
      unordered_map<Node* , bool>vis;
      queue<Node*>q;
      q.push(target);
      vis[target]= true;
      int maxi = 0;
      while(!q.empty()){
         int flag = 0;
          int size = q.size();
          for(int i=0;i<size;i++){
          Node * node = q.front();
          q.pop();
          
          if(node->left && !vis[node->left]){
              flag =1;
              q.push(node->left);
              vis[node->left] = true;
          }
          if(node->right && !vis[node->right]){
              flag = 1 ;
              q.push(node->right);
              vis[node->right]=true;
          }
          if(parent_track.count(node)&& !vis[parent_track[node]]){
              flag = 1;
              q.push(parent_track[node]);
              vis[parent_track[node]]=true;
          }
          }
          
          if(flag) maxi++;
      }
      return maxi;
  }
  
  
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node* , Node*>parent_track;
        Node* targetNode = mark(root, parent_track, target);
        
        return maxi(parent_track , targetNode);
    }
};