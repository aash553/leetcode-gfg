class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        int start  = 0;
        int count = 0;
        int minlen = INT_MAX;
        int l = 0 , r =0;

        if(n<m) return "";

        map<char, int >mpp;
        for(auto ch : t){
            mpp[ch]++;
        }

        count = mpp.size();

        while(r<n){
            if(mpp.find(s[r]) != mpp.end()){
                mpp[s[r]]--;
                if(mpp[s[r]] == 0)
                count--;
            }
            while(count == 0){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
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