// User function Template for C++
class Solution {
  public:
  
  
  void topo(int node , stack<int>&st ,  vector<int>&vis,vector<vector<pair<int,int>>>&adj){
      vis[node] = 1;
      for(auto actualnode : adj[node]){
          int v = actualnode.first; // first is the node 
          if(!vis[v]){
              topo(v,st,vis,adj);
          }
      }
      st.push(node);
  }
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
       vector<vector<pair<int,int>>>adj(V);
       for(int i =0;i<E;i++){
           int u = edges[i][0];
           int v = edges[i][1];
           int wt = edges[i][2];
           adj[u].push_back({v,wt});
       }
       vector<int>vis(V,0);
       stack<int>st;
       for(int i=0;i<V;i++){
           if(!vis[i]){
               topo(i,st,vis,adj);
           }
       }
       //step 2 
       vector<int>dis(V,INT_MAX);
       dis[0] = 0;
       while(!st.empty()){
           int node = st.top();
           st.pop();
           if(dis[node] != INT_MAX){
           for(auto it : adj[node]){
               int v = it.first;
               int wt = it.second;
               if(dis[node] + wt < dis[v]){
                   dis[v] = dis[node] + wt;
               }
           }
       }
           }
          for(int i = 0; i < V; i++) {
           if(dis[i] == INT_MAX) dis[i] = -1;
       }
       return dis;
    }
};
