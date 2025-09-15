class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int hash[256];
        int n = s.length();
        fill(hash,hash+256,-1);
        int maxlen = 0;

        if(n<=1) return n;
        while(r<n){
            //already there in the hash table and also check the bounds
            if(hash[s[r]] != -1 &&  hash[s[r]] >= l){
                 l= hash[s[r]]+1;
        }
        int len = r-l+1;
        maxlen = max(len,maxlen);
        hash[s[r]] = r;
        r++;
        }
        return maxlen;
    }
};