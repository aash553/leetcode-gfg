class Solution {
public:

    bool dfs(int node , vector<int>&vis ,  vector<int>&pathvis , vector<vector<int>>& adjlist){
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto actualnode : adjlist[node]){
            if(!vis[actualnode]){
                if(dfs(actualnode , vis, pathvis , adjlist) == false) return false;
            }else if (pathvis[actualnode]){
                return false;
            }
        }
        pathvis[node] = 0;
        return true;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses,0);
        vector<int>pathvis(numCourses,0);

        vector<vector<int>>adjlist(numCourses);
        for(auto e : prerequisites){
            int u = e[0];
            int v = e[1];
            adjlist[v].push_back(u);
        }

        for(int i =0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathvis,adjlist)==false) return false;
            }
        }
        return true;
    }
};