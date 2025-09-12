class Solution {
public:

    vector<vector<int>>t;
    int solve(int m , int n){
        // base case 
        int i = m-1;
        int j = n-1;
        if(i==0 && j ==0 ) return 1;
        if(i< 0 || j < 0 ) return 0;

        if(t[i][j] != -1) return t[i][j];
        int totalpath = 0;
            int right = solve(i+1,j);
            int down = solve(i,j+1);
            totalpath = right + down;

        return t[i][j] = totalpath;
    }

    int uniquePaths(int m, int n) {
        t.assign(m,vector<int>(n+1,-1));
        return solve(m,n);
    }
};