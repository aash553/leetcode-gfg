class Solution {
public:

    unordered_map<string,bool>dp;

    bool solve( const string &s1 , const string &s2){
    if(s1.compare(s2) == 0) return true;
    if(s1.length() != s2.length()) return false;
    if(s1.length() <= 1) return false;

    string key = s1+ " " + s2;
    if(dp.find(key) != dp.end()) return dp[key];
    int n = s1.length();
    bool flag = false;

    for(int i = 1; i < n; i++){
        // Case 1: With swap
        if( solve(s1.substr(0,i), s2.substr(n-i,i)) &&
            solve(s1.substr(i, n-i), s2.substr(0,n-i)) )
        {
            flag = true;
            break;
        }

        // Case 2: Without swap
        if( solve(s1.substr(0,i), s2.substr(0,i)) &&
            solve(s1.substr(i, n-i), s2.substr(i, n-i)) )
        {
            flag = true;
            break;
        }
    }
    return dp[key] = flag;
}
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        int m = s1.length();
        int n = s2.length();
        return solve(s1,s2);
    }
};