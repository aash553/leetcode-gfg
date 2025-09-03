class Solution {
public:

    void bfs(int node , vector<int>&vis, vector<vector<int>>&isConnected){
        vis[node] = 1;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int j =0;j<isConnected.size();j++){
                if(isConnected[curr][j] == 1 && !vis[j]){
                    vis[j] = 1;
                    q.push(j);
                }
            }
        }
    }

     int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
            //dfs funtion call
            vector<int>vis(n,0);
            int cnt = 0;
            for(int i =0;i<n;i++){
            if(!vis[i]){
                cnt++;
               bfs(i,vis,isConnected);
            }
            }
            return cnt;
    }
};