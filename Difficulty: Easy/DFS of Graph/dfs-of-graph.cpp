class Solution {
  public:
  
  void solve(int node , vector<int>&ls , vector<int> &vis, vector<vector<int>>& adj){
      
      vis[node] = 1;
      ls.push_back(node);
      for(auto it : adj[node]){
          if(!vis[it]){
              solve(it,ls,vis,adj);
          }
      }
  }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>ls;
        int n = adj.size();
         vector<int>vis(n,0);
        solve(0,ls,vis,adj);
        return ls;
    }
};