class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int m = s.length();
        string b = s;
        reverse(b.begin(),b.end());
        int n = b.length();

        vector<vector<int>>t(m+1,vector<int>(n+1,-1));
        for(int i =0;i<=m;i++){
            for(int j =0 ;j<=n;j++){
                if(i==0 || j ==0){
                    t[i][j] = 0;
                }
            }
        }
        for(int i =1;i<m+1;i++){
            for(int j =1;j<n+1;j++){
                if(s[i-1]==b[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[m][n];
    }
};