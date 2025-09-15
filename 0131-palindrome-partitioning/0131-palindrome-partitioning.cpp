class Solution {
public:

    bool ispalindrome(string & s, int left , int right ){
        while(left < right ){
            if(s[left] != s[right]) return false ;
            left ++;
            right--;
        }
        return true;
    }

    void solve(string &s , int i , vector<string>&ds , vector<vector<string>>&ans){
        int n = s.length();
        if(i==n){
           ans.push_back(ds);
           return;
        }
        for(int j = i ;j <n ;j++){
        if(ispalindrome(s,i,j)){
        ds.push_back(s.substr(i,j-i+1));
        solve(s,j+1,ds,ans);
        ds.pop_back();
        }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        solve(s , 0 , ds, ans);
        return ans;
    }
};