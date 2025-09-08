class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        int n = grid.size();
        int m = grid[0].size();
         if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

        vector<vector<int>>dist(n,vector<int>(m,1e9));
        q.push({1,{0,0}});
         dist[0][0] = 1;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

             if(row == n-1 && col == m-1) return dis;

            for(int dr = -1 ; dr<=1 ; dr++){
                for(int dc = -1 ;dc<=1;dc++){
                    if(dr == 0 && dc == 0)continue;
                        int nrow = row + dr;
                        int ncol = col +dc;
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 0 &&
                         dis + 1 < dist[nrow][ncol]
                         ){
                            dist[nrow][ncol] = 1+dis;
                            q.push({1+dis,{nrow,ncol}});
                         }
                }
            }
        }
        return -1;
    }
};