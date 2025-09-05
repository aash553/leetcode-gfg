// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
            vector<vector<pair<int,int>>> adj(V);
        for(auto &e : edges){
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w}); // if undirected
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dis(V);
        for(int i =0;i<V;i++)dis[i] = 1e9;
        dis[src]=0;
        pq.push({0,src});
        
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjnode = it.first;
                int edgeweight = it.second;
                if(d + edgeweight < dis[adjnode]){
                    dis[adjnode] = d + edgeweight;
                    pq.push({dis[adjnode],adjnode});
                }
            }
        }
        return dis;
    }
};