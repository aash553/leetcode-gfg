class Solution {
public:

    void solve(int n , int open ,int close ,vector<string>&ans ,string curr_str){

        if(curr_str.size() == n*2){
            ans.push_back(curr_str);
            return;
        }

        if(open<n)solve(n,open+1,close,ans,curr_str+'(');
        if(close<open) solve(n,open,close+1,ans,curr_str+')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(n,0,0,ans,"");
        return ans;
    }
};