class Solution {
  public:
  
  bool detect(int node ,  vector<vector<int>>&adjls ,vector<int>&vis){
      queue<pair<int,int>>q;
      vis[node] =1;
      q.push({node,-1});
      
      while(!q.empty()){
          int actualnode = q.front().first;
          int parent = q.front().second;
          q.pop();
          
          for(auto adjacentlist : adjls[actualnode]){
              if(!vis[adjacentlist]){
                  vis[adjacentlist] = 1;
                  q.push({adjacentlist,actualnode});
              }else if(parent != adjacentlist){
                  return true;
              }
          }
      }
      return false;
  }
  
  
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        //this is for the adjacenty list
        vector<vector<int>>adjls(V);
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            adjls[v].push_back(u);
            adjls[u].push_back(v);
        }
        
        vector<int>vis(V,0);
        
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adjls,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};