class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<vector<int>>ans = image;
        int n = image.size();
        int m = image[0].size();

        int inicolor = image[sr][sc];
        if (inicolor == color) return ans;

        queue<pair<int,int>>q;
        q.push({sr,sc});
        ans[sr][sc] = color;

        while(!q.empty()){
            auto[row,col] = q.front();
            q.pop();

            int delrow[] = {-1,1,0,0};
            int delcol[] = {0,0,-1,1};

            for(int i = 0 ;i<4 ; i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
            if(nrow < n && nrow >= 0 && ncol < m && ncol>=0 && ans[nrow][ncol] == inicolor){
                ans[nrow][ncol] = color;
                q.push({nrow,ncol});
            }
            }
        }
        return ans;
    }
};