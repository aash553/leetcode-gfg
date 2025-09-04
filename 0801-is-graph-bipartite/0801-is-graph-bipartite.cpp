class Solution {
public:

    bool check (int start , int n , vector<int>&color , vector<vector<int>>& graph){
        queue<int>q;
        q.push(start);
        color[start] =0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto actualnode : graph[node]){
                if(color[actualnode] == -1){
                    color[actualnode] = !color[node];
                    q.push(actualnode);
                }
                else if(color[actualnode] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i = 0 ;i<n;i++){
            if(color[i] == -1){
                if(check(i,n,color,graph) == false){
                    return false;
                }
            }
        }
        return true;
    }
};