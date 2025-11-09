class Solution {
public:

    void dfs(int row , int col , vector<vector<int>>&vis , vector<vector<char>>& grid){
        vis[row][col] =1;
        int n = grid.size();
        int m = grid[0].size();

        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,-1,1};

        for(int i = 0 ;i<4 ;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow < n && nrow >=0 && ncol < m && ncol >= 0 && !vis[nrow][ncol] && grid[nrow][ncol] =='1'){
                dfs(nrow,ncol,vis,grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1' ){
                    cnt +=1;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};