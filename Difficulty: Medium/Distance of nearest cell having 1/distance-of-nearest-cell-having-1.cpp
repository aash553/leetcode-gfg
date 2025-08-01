class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        
        queue<pair<pair<int,int>,int>>q;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            dist[row][col] = dis;
            int delrow[] = {-1,1,0,0};
            int delcol[] = {0,0,-1,1};
            for(int i =0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col +delcol[i];
                if(nrow >=0 && nrow < n && ncol >= 0 && ncol <m && vis[nrow][ncol] == 0){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},dis+1});
                }
            }
        }
        return dist;
    }
};