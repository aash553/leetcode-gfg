class Solution {
public:
    string minWindow(string s, string t) {
        int r = 0;
        int l = 0;
        int start = 0;
        int n = s.length();
        int minlen = INT_MAX;
        int count = 0;
        unordered_map<char,int>mpp;
        for(auto ch : t){
            mpp[ch]++;
        }
        count = mpp.size();
        while(r<n){
            if(mpp.find(s[r])!= mpp.end()){
                mpp[s[r]]--;
                if(mpp[s[r]] ==0)
                count--;
            }
            while(count == 0){
                int len = r-l+1;
                if(len < minlen){
                minlen = len;
                start = l;
                }
            if(mpp.find(s[l]) != mpp.end()){
                mpp[s[l]]++;
                if(mpp[s[l]] == 1)
                count++;
            }
            l++;
        }
        r++;
        }
        if(minlen == INT_MAX) return "";
        return s.substr(start,minlen);
    }
};