class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n = s1.length();
        int m = s2.length();

        if(n>m) return false;

        vector<int>freq1(26,0) , freq2(26,0);

        for(int i = 0;i<n ;i++){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }

        for(int i = n ; i<m ;i++){
            if(freq1 == freq2) return true;

            freq2[s2[i]-'a']++;
            freq2[s2[i-s1.length()]-'a']--;
        }
        return (freq1==freq2);
    }
};