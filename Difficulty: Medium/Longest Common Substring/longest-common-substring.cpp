class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        //top down 
        int m = s1.length();
        int n = s2.length();
        //intitnalization
        vector<vector<int>>t(m+1,vector<int>(n+1,-1));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j == 0){
                    t[i][j] =0;
                }
            }
        }
        
        int maxlength = 0;
        for(int i =1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(s1[i-1] == s2[j-1]){
                    t[i][j] = 1+t[i-1][j-1];
                    maxlength = max(maxlength,t[i][j]);
                }else{
                    t[i][j] = 0;
                }
            }
        }
        return maxlength;
    }
};