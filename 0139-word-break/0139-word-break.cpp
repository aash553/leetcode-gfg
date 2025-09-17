class Solution {
public:

    vector<int>t;
    bool solve(string &s , int i ,  unordered_set<string>&st){
        int n = s.length();
        //base case 
        if(i==n){
            return true;
        }
        if(t[i] != -1) return t[i];
        for(int j = i ; j<n;j++){
            string sub = s.substr(i,j-i+1);
            if(st.count(sub) && solve(s,j+1,st))
            return t[i] =  true;
        }
        return t[i] =  false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string>st;
        for(auto it : wordDict){
            st.insert(it);
        }
        t.assign(n,-1);
        return solve(s,0,st);
    }
};