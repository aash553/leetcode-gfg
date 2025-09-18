class Solution {
  public:
  
  
    void solve(int row , int col , vector<string>&ans ,vector<vector<int>>&vis,vector<vector<int>>& maze , string move ){
        int n = maze.size();
        int m = maze[0].size();
        
       if(row == n-1 && col == m-1){
           ans.push_back(move);
           return;
       }
       string dir = "DLRU";
       int delrow[] = {1,0,0,-1};
       int delcol[] = {0,-1,1,0};
       for(int i =0;i<4;i++){
           int nrow = row + delrow[i];
           int ncol = col + delcol[i];
           if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && maze[nrow][ncol] == 1){
               vis[nrow][ncol] = 1;
               solve(nrow,ncol,ans,vis,maze,move+dir[i]);
               vis[nrow][ncol] = 0;
           }
       }
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        int m = maze[0].size();
        
        vector<string>ans;
        vector<vector<int>>vis(n,vector<int>(m,0));
        if(maze[0][0]==1){
            vis[0][0] = 1;
        solve(0,0,ans,vis,maze,"");
        }
        return ans;
    }
};