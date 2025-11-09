class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        

        vector<vector<pair<int,int>>>adjlist(n+1);

        for(auto e : times){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adjlist[u].push_back({v,w});
        }

        priority_queue<pair<int,int>,
         vector<pair<int,int>>,
         greater<pair<int,int>>>q;

         vector<int> dis(n+1, 1e9);
         dis[k] = 0;

         q.push({0,k});

         while(!q.empty()){
            int d = q.top().first;
            int node = q.top().second;
            q.pop();
            for(auto it : adjlist[node]){
                int adjnode = it.first;
                int edgeweight = it.second;

                if(d+edgeweight < dis[adjnode]){
                    dis[adjnode] = d + edgeweight;;
                    q.push({dis[adjnode],adjnode});
                }
            }
         }
         int ans = 0;
         for(int i = 1;i<=n;i++){
            if(dis[i] == 1e9) return -1;
            ans = max(ans,dis[i]);
         }
         return ans;
    }
};