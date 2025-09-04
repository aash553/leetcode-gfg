class Solution {
public:

    bool dfs(int node , vector<int>&vis , vector<int>&pathvis,vector<vector<int>>& graph , vector<int>&check ){
        vis[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;
        for(auto actualnode : graph[node]){
            if(!vis[actualnode]){
                if(dfs(actualnode , vis ,pathvis, graph , check) == true) return true;
            }
            else if( vis[actualnode] && pathvis[actualnode]){
                return true;
            }
        }
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }


    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        vector<int>check(n,0);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,pathvis,graph,check);
            }
        }
        for(int i =0;i<n;i++){
            if(check[i] == 1) ans.push_back(i);
        }
        return ans;
    }
};