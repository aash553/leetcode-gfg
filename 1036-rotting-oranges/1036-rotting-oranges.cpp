class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>ans = grid;
        
        vector<vector<int>>vis(n,vector<int>(m,0));

        queue<pair<int,pair<int,int>>>q;

        for(int i = 0;i<n;i++){
            for(int j = 0 ;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({0,{i,j}});
                    vis[i][j] = 2;
                }else{
                    vis[i][j] = 0;
                }
            } 
        }

        int tm = 0;
        while(!q.empty()){
            auto[time ,pos] = q.front();
            int row = pos.first;
            int col = pos.second;
            q.pop();
            tm = max(tm,time);
            int delrow[] = {-1,1,0,0};
            int delcol[] = {0,0,-1,1};

            for(int i =0 ;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

            if(nrow < n && nrow >= 0 && ncol  < m && ncol >= 0 && vis[nrow][ncol]!=2 && ans[nrow][ncol] == 1){
                vis[nrow][ncol] = 2;
                q.push({time+1,{nrow,ncol}});
                ans[nrow][ncol] = 2;
            }
            }
        }

        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ans[i][j] == 1 && vis[i][j] !=2){
                    return -1;
                }
            }
        }
        return tm;
    }
};