class Solution {
  public:
  
  void dfs(int node , vector<vector<int>>&adjlist,vector<int>&vis,stack<int>&st){
      vis[node] = 1;
      for(auto actualnode : adjlist[node]){
          if(!vis[actualnode]){
              dfs(actualnode , adjlist, vis ,st);
          }
      }
      st.push(node); // if no adjacent list just push into the stack
  }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        
        //adjlist creation
        vector<vector<int>>adjlist(V);
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            adjlist[u].push_back(v);
        }
        
        vector<int>vis(V,0);
        stack<int>st;
        for(int i = 0 ;i<V;i++){
            if(!vis[i]){
                dfs(i,adjlist,vis,st);
            }
        }
        
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};