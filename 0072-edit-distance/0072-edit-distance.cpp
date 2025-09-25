class Solution {
public:
   
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
       vector<vector<int>>t(n+1,vector<int>(m+1,-1));

        for (int i = 0; i <= n; i++) t[i][0] = i;
        for (int j = 0; j <= m; j++) t[0][j] = j;


        for(int i =1;i<n+1;i++){
            for(int j = 1 ;j<m+1 ; j++){
                if(word1[i-1] == word2[j-1]){
                    t[i][j] = t[i-1][j-1];
                }else {
                   t[i][j]  = 1 + min({
                        t[i][j-1],
                        t[i-1][j],
                        t[i-1][j-1]
                    });
                }
            }
        }
        return t[n][m];
    }
};