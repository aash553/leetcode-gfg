class Solution {
public:

    vector<int>t;
    bool solve(string &s, int i , set<string>&st){
        int n = s.length();
        if(i==s.length()){
            return true;
        }

        if(t[i] != -1) return t[i];
            for(int j = i ; j<n;j++){
                string sub = s.substr(i,j-i+1);
                if(st.count(sub)){
                    if(solve(s,j+1,st))
                    return t[i] = true;
                }
    }
            return t[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        set<string>st;
        for(auto it : wordDict){
            st.insert(it);
        }
        t.assign(n,-1);
        return solve(s,0,st);
    }
};