class Solution {
public:

    unordered_map<string,int>mp;
    int solve(string &s, int i, int j, bool isTrue) {
        if (i > j) return 0;
        if (i == j) {
            if (isTrue) return (s[i] == 'T');
            else return (s[i] == 'F');
        }
        
        string temp = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);
        
        if (mp.find(temp) != mp.end()) {
            return mp[temp];
        }
        
        int ans = 0;
        for (int k = i+1; k <= j-1; k+=2) {
            int lt = solve(s, i, k-1, true);
            int lf = solve(s, i, k-1, false);
            int rt = solve(s, k+1, j, true);
            int rf = solve(s, k+1, j, false);

            if (s[k] == '&') {
                if (isTrue) ans += lt * rt;
                else ans += lf * rt + lt * rf + lf * rf;
            }
            else if (s[k] == '|') {
                if (isTrue) ans += lt * rt + lt * rf + lf * rt;
                else ans += lf * rf;
            }
            else if (s[k] == '^') {
                if (isTrue) ans += lt * rf + lf * rt;
                else ans += lt * rt + lf * rf;
            }
        }
        mp[temp] = ans;
        return mp[temp];
    }

    int countWays(string &s) {
        int n = s.length();
        return solve(s, 0, n-1, true);
    }
};
