class Solution {
  public:
  
  void dfs(int node ,vector<int>&vis , stack<int>&st ,  vector<vector<int>>&adjlist){
      vis[node] = 1;
      for(auto actualnode : adjlist[node]){
          if(!vis[actualnode]){
              dfs(actualnode , vis, st, adjlist);
          }
      }
    st.push(node);
  }
  
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adjlist(V);
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            adjlist[u].push_back(v);
        }
        stack<int>st;
        vector<int>vis(V,0);
        for(int i =0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,st,adjlist);
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