class Solution {
public:

    vector<vector<int>>t;
    int solve(vector<vector<int>>& grid, int row , int col){
        //base case 
        int n = grid.size();
        int m = grid[0].size();

        if(row == n-1 && col == m-1) return grid[row][col];
        if(t[row][col] != -1) return t[row][col];

        if(row >= n || col >= m) return INT_MAX;
        int right = solve(grid,row,col+1);
        int down = solve(grid,row+1,col);

        return t[row][col] =  grid[row][col] + min(right,down);
    }

    int minPathSum(vector<vector<int>>& grid) {
         int n = grid.size();
        int m = grid[0].size();
        t.assign(n+1,vector<int>(m+1,-1));
        return solve(grid,0,0);
    }
};