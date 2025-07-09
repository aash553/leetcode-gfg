class Solution {
public:

unordered_set<string>st;

bool solve(int ind , string & s, vector<int>&dp){
        
    int n = s.length();
    if(ind == n){
        return true;
    }

     if (dp[ind] != -1) return dp[ind];
     
    if (st.find(s) != st.end()) 
    return true;

        for(int l=1;l<=n;l++){
            string temp = s.substr(ind,l);
            if(st.find(temp)!=st.end() &&  solve(ind+l,s,dp)){
                return dp[ind] = true;
            }
        }
        return dp[ind]=false;
}

    
    bool wordBreak(string s, vector<string>& wordDict) {


        for(string &word : wordDict){
            st.insert(word);
        }
        int n = s.length();
        vector<int>dp(n+1,-1);

        return solve(0,s,dp);

    }
};