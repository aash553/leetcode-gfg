class Solution {
  public:
  
  bool check(int start , int V , vector<int>&color , vector<vector<int>>&adjlist){
      color[start] = 0;
      queue<int>q;
      q.push(start);
      while(!q.empty()){
          int node = q.front();
          q.pop();
          for(auto actualnode : adjlist[node]){
              if(color[actualnode] == -1){
                  color[actualnode] =! color[node];
                  q.push(actualnode);
              }
              else if(color[actualnode] == color[node]){
                  return false;
              }
          }
      }
      return true;
  }
  
  
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        //make the adjacenty list
        vector<vector<int>>adjlist(V);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adjlist[v].push_back(u);
            adjlist[u].push_back(v);
        }
        vector<int>color(V,-1);
        for(int i =0;i<V;i++){
            color[i] = -1;
        }
        for(int i =0;i<V;i++){
            if(color[i] == -1){
            if(check(i,V,color,adjlist) == false){
                return false;
            }
            }
        }
        return true;
    }
};