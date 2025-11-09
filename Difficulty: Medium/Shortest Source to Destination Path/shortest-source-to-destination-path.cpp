// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        
        if (A[0][0] == 0) return -1;
        
        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,-1,1};
        
        vector<vector<int>>vis(N, vector<int>(M,0));
        
        queue<pair<pair<int,int>,int>>q;
        
        q.push({{0,0},0});
        vis[0][0] = 1;
    
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            int row = front.first.first;
            int col = front.first.second;
            int t = front.second;
            
            if (row == X && col == Y) 
                return t;
            
            for(int i =0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
            
            if(nrow < N && nrow >= 0 && ncol < M && !vis[nrow][ncol] && A[nrow][ncol] == 1){
                vis[nrow][ncol] = 1;
                q.push({{nrow,ncol},t+1});
            }
            }
        }
        return -1;
    }
};