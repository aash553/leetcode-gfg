class Solution {
public:

    void bfs(int node , vector<int>&vis , vector<vector<int>>&adjlist){

        vis[node] = 1;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto it : adjlist[curr]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adjlist(n);
        for(int i = 0;i<n;i++){
            for(int  j =0;j<n;j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adjlist[i].push_back(j);
                }
            }
        }

        vector<int>vis(n,0);
        int cnt = 0 ;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                cnt++;
                bfs(i,vis,adjlist);
            }
        }
        return cnt;
    }
};