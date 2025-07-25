class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mpp;

        int l= 0;
        int r =0;
        int n = s.length();
        int maxi = 0;
        while(r<n){
            if(mpp.find(s[r])!=mpp.end() && mpp[s[r]] >= l) {
                l = mpp[s[r]]+1;
            }

            mpp[s[r]]=r;
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};