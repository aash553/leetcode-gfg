class Solution {
public:
    int characterReplacement(string s, int k) {
        int l =0;
        int r =0;
        int hash[26]={0};
        fill(hash,hash+26,0);
        int n = s.length();
        int maxlen = 0; 
        int maxfreq =0;
        

        while(r<s.size()){
            hash[s[r]-'A']++;
            maxfreq= max(maxfreq,hash[s[r]-'A']);
        if((r-l+1)-maxfreq>k){
            hash[s[l]-'A']--;
            l++;
        }
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};