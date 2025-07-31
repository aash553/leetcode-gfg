class Solution {
public:


    void dfs(int row, int col,int inicolor,vector<vector<int>>&ans,vector<vector<int>>& image ,int color){
        int n = image.size();
        int m = image[0].size();

        ans[row][col] = color;

        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,-1,1};
        for(int i =0;i<4;i++){
            int nrow = row+delrow[i];
            int ncol = col + delcol[i];
        if(nrow>=0 && nrow<n && ncol >=0 && ncol < m && ans[nrow][ncol] == inicolor && ans[nrow][ncol] != color){
            dfs(nrow,ncol,inicolor,ans,image,color);
        }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans = image;
        int inicolor = image[sr][sc];
        dfs(sr,sc,inicolor,ans,image, color);
        return ans;
    }
};