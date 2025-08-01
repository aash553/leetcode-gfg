class Solution {
    
    
  private:
  
  bool detect(int src , vector<int>adjLs[] , int vis[]){
      vis[src]=1;
      queue<pair<int,int>>q;
      q.push({src,-1});
      while(!q.empty()){
          int node = q.front().first;
          int parent = q.front().second;
          q.pop();
          
          
          for(auto adjacentlist : adjLs[node]){
              if(!vis[adjacentlist]){
                  vis[adjacentlist]=1;
                  q.push({adjacentlist,node});
              }
              else if (parent != adjacentlist){
                  return true;
              }
          }
      }
      return false;
  }
    
    
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int>adjLs[V];
        for( auto &e : edges){
            int v = e[0];
            int u = e[1];
            adjLs[v].push_back(u);
            adjLs[u].push_back(v);
        }
        
        int vis[V] = {0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
            if(detect(i,adjLs,vis)){
                return true;
            }
            }
        }
        return false;
    }
};