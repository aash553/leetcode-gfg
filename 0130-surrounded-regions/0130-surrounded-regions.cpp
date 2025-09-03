class Solution {
public:

    void dfs(int row , int col , vector<vector<int>>&vis ,  vector<vector<char>>& board ){
        int n = board.size(); // row
        int m = board[0].size(); //col
        vis[row][col] = 1;
        int delrow[]={-1,1,0,0};
        int delcol[]={0,0,1,-1};
        for(int i =0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow < n && ncol >=0 && ncol <m && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                dfs(nrow,ncol,vis,board);
            }
        }
    }


    void solve(vector<vector<char>>& board) {
        //so first we require visisted matrix
        int n = board.size(); // row
        int m = board[0].size(); //col
        vector<vector<int>>vis(n,vector<int>(m,0));

        // we have to traverse all the boundaries 
        //traversin the top and bottom boundaries

        for(int j=0;j<m;j++){
            // for the top row 
            if(board[0][j] == 'O' && !vis[0][j]){
                dfs(0,j,vis,board);
            }
            //for the last row 
            if(board[n-1][j] == 'O' && !vis[n-1][j]){
                dfs(n-1,j,vis,board);
            }
        }

        for(int i =0;i<n;i++){
            //left boundary
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i,0,vis,board);
            }
            //right boundary
            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                dfs(i,m-1,vis,board);
            }
        }
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                board[i][j] = 'X';
                }
            }
        }
    }
};