class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
         const int MOD = 1e9 + 7;
        vector<vector<pair<int,int>>>adjlist(n);
        for(auto it : roads){
            adjlist[it[0]].push_back({it[1],it[2]});
            adjlist[it[1]].push_back({it[0],it[2]});
        }

        vector<long long >dis(n,1e15) ; vector<int>ways(n,0);
        dis[0]=0;
        ways[0]=1;
        priority_queue<pair<long long  ,long long >,
                      vector<pair<long long  ,long long >>,
                      greater<pair<long long  ,long long>>>pq;

        pq.push({0,0});

        while(!pq.empty()){
            auto it = pq.top();
            long long  d = it.first;
            long long  node = it.second;
            pq.pop();

            if(d>dis[node]) continue; 

            for(auto iter : adjlist[node]){
                long long  adjnode = iter.first;
                long long  ew = iter.second;

                if(d+ew < dis[adjnode]){
                    dis[adjnode] = d+ew;
                    pq.push({d+ew , adjnode});
                    ways[adjnode] = ways[node];
                }else if(d+ew == dis[adjnode]){
                    ways[adjnode] = (ways[adjnode] + ways[node])%MOD;
                }
            }
        }
       return ways[n-1];
    }
};