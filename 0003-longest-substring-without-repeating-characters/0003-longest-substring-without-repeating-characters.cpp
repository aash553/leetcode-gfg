class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int hash[256];
        fill(hash,hash+256,-1);
        int r = 0 , l=0;
        int maxlen = 0;

        //base case 
        if(n<=1) return n ;

        while(r<n){
            if(hash[s[r]] != -1 && hash[s[r]] >= l ){
                l = hash[s[r]] +1 ;
            } 
            int cnt = r-l+1;
            maxlen = max(maxlen,cnt);
            hash[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};