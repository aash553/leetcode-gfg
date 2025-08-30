class Solution {
public:

vector<vector<int>>t;
    bool solve(string &s, string &p, int m , int n){
        //base condition 
        if(m==0 && n==0) return true;
        if(m>0 && n==0) return false;
        if(n>0 && m==0){
            for(int i=0;i<n;i++){
                if(p[i] != '*'){
                    return false;
                }
            }
        return true;
        }

        if(t[m][n] != -1) return t[m][n];
        //choice diagram;
        if(s[m-1] == p[n-1] || p[n-1] == '?'){
            return t[m][n] = solve(s,p,m-1,n-1);
        }

        if(p[n-1] == '*'){
            return t[m][n] =  solve(s,p,m-1,n) || solve(s,p,m,n-1);
        }
        return t[m][n] = false;
    }


    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        t.assign(m+1,vector<int>(n+1,-1));
        return solve(s,p,m,n);
    }
};