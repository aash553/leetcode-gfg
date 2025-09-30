class Solution {
public:
    vector<vector<int>>t;
    bool ispalindrome(string &s, int i , int j){

            if(i>=j) return true;
            if(t[i][j] != -1) return t[i][j];
            t[i][j] = (s[i] == s[j] && ispalindrome(s,i+1,j-1)) ? 1 : 0;
            return t[i][j];
    }
    void solve(string &s , int i , int j , int &maxlen , int &start){
        //base case 
        int n = s.length();
        if(i==n) return;
        if(j<n){
            if(ispalindrome(s,i,j) && j-i+1 > maxlen){
                maxlen = j-i+1;
                start = i;
            }
            solve(s,i,j+1,maxlen,start);
        }
        else{
            solve(s,i+1,i+1,maxlen,start);
        }
    }
    string longestPalindrome(string s) {
        int start = 0;
        int n = s.length();
        int maxlen = 1;
        t.assign(n,vector<int>(n+1,-1));
        solve(s,0,0,maxlen,start);
        return s.substr(start , maxlen);
    }
};