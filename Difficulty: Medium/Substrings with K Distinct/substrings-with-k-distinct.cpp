class Solution {
public:
    int solve(string &s, int k) {
        if (k == 0) return 0;  // No substring can have 0 distinct characters
        
        int n = s.length();
        int freq[26] = {0};  // Array instead of map for better performance
        int distinctCount = 0;
        int l = 0;
        int r = 0;
        int cnt = 0;
        
        while (r < n) {
            if (freq[s[r] - 'a'] == 0) {
                distinctCount++;
            }
            freq[s[r] - 'a']++;
            
            while (distinctCount > k) {
                freq[s[l] - 'a']--;
                if (freq[s[l] - 'a'] == 0) {
                    distinctCount--;
                }
                l++;
            }
            
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }
    
    int countSubstr(string& s, int k) {
        if (k == 0) return 0;
        return solve(s, k) - solve(s, k - 1);
    }
};