class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void solve(string &s, int i, int j, int &maxLen, int &start) {
        int n = s.size();
        if(i == n) return;

        if(j < n) {
            if(isPalindrome(s, i, j) && j-i+1 > maxLen) {
                maxLen = j-i+1;
                start = i;
            }
            solve(s, i, j+1, maxLen, start);
        } else {
            solve(s, i+1, i+1, maxLen, start);
        }
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 1;
        int start = 0;
        solve(s, 0, 0, maxLen, start);
        return s.substr(start, maxLen);
    }
};
