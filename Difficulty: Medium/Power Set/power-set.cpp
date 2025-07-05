class Solution {
  public:
  
  
    void solve(int ind , string &s , string curr, vector<string>&ans){
        if(ind == s.size()){
            if(!curr.empty()){
                ans.push_back(curr);
            }
            return;
        }
        
        solve(ind+1,s,curr+s[ind],ans);
        solve(ind+1,s,curr,ans);
    }
  
    vector<string> AllPossibleStrings(string s) {
        vector<string>ans;
        solve(0,s,"",ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};