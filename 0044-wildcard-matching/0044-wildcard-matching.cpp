class Solution {
public:
    bool isMatch(string s, string p) {
        
        int m = s.length();
        int n = p.length();

        vector<vector<bool>>t(m+1,vector<bool>(n+1,false));
        t[0][0] = true;
        for(int i =1;i<=m;i++){
            t[i][0] = false;
        }

      bool flag = true;
        for(int j = 1; j <= n; j++){
            if(p[j-1] != '*'){
                flag = false;
            }
            t[0][j] = flag;
        }

        for(int i =1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    t[i][j] = t[i-1][j-1];
                }else if(p[j-1] == '*'){
                    t[i][j] = t[i-1][j] || t[i][j-1];
                }else{
                    t[i][j] = false;
                }
            }
        }
        return t[m][n];
    }
};