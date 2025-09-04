class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjlist(numCourses);
        for(auto e : prerequisites){
            int u = e[0];
            int v = e[1];
            adjlist[v].push_back(u);
        }

        vector<int>indegree(numCourses,0);
        for(int i =0;i<numCourses;i++){
            for(auto it : adjlist[i]){
                indegree[it]++;
            }
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto actualnode : adjlist[node]){
                indegree[actualnode] --;
                if(indegree[actualnode] == 0){
                    q.push(actualnode);
                }
            }
        }
        if(topo.size() == numCourses) return topo;
        return {};
    }
};