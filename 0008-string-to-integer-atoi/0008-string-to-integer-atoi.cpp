class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        long ans = 0;
        int sign = 1;

        // Step 1: Skip leading whitespaces
        while(i < n && s[i] == ' ') i++;

        // Step 2: Check for optional '+' or '-'
        if(i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while(i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            // this is for overfllow
            if(sign == 1 && ans > INT_MAX) return INT_MAX;
            if(sign == -1 && -1 * ans < INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(sign * ans);
    }
};
