class Solution {
public:

    bool isvalid(string str){
        if(str[0]=='0')
        return false;

        int val = stoi(str);
        if(val>255)
        return false;

        return true;
    }

    void solve(string &s , int ind , int parts , string curr , vector<string>&result){
        int n = s.length();
        if(ind==n && parts == 4){
            curr.pop_back();
            result.push_back(curr);
            return;
        }

        if(ind+1<=n){
            solve(s,ind+1,parts+1,curr+s.substr(ind,1)+".",result);
        }

        if(ind+2<=n && isvalid(s.substr(ind,2))){
             solve(s,ind+2,parts+1,curr+s.substr(ind,2)+".",result);
        }

 if(ind+3<=n && isvalid(s.substr(ind,3))){
             solve(s,ind+3,parts+1,curr+s.substr(ind,3)+".",result);
        }

    }

    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        vector<string>result;
        int parts=0;
        solve(s,0,parts,"",result);
        return result;
    }
};