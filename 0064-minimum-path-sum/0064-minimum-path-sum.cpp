class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> t(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0){
                    t[i][j] = grid[i][j];
                } else {
                    int up = (i > 0) ? t[i-1][j] : 1e9;
                    int left = (j > 0) ? t[i][j-1] : 1e9;
                    t[i][j] = grid[i][j] + min(up, left);
                }
            }
        }

        return t[n-1][m-1];
    }
};
