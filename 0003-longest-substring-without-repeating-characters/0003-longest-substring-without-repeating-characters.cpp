class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0; 
        int r = 0;
        int maxi = 0 ;
        int hash[256];
        fill(hash,hash+256,-1);
        int n = s.length();

        if(n<=1) return n;

        while(r<n){
        
            if(hash[s[r]]!=-1) 
            // it means its present 
            {
                if( hash[s[r]] >= l){
                    l=hash[s[r]]+1;
                }
            }
            int len = r-l+1;
            maxi = max(maxi,len);
            hash[s[r]] = r;
            r++;
        }
        return maxi;
    }
};