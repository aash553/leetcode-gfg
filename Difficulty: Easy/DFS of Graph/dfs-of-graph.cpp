class Solution {
    
    
    private:
    
    void solve(int node ,vector<int>& vis, vector<int>&ls , vector<vector<int>>& adj ){
        
        vis[node]=1;
        ls.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                solve(it,vis,ls, adj);
            }
        }
    }
    
    
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        
        int n = adj.size();
         vector<int> vis(n, 0);
        vector<int>ls;
        solve(0,vis,ls,adj);
        return ls;
    }
};