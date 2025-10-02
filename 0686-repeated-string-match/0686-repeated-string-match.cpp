class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();

        int repeats = (m+n-1)/n;

        string repeated = "";
        for(int i = 0 ;i<repeats ;i++) repeated += a;

        if(repeated.find(b) != string :: npos) return repeats;

        repeated += a;

        if(repeated.find(b) != string :: npos) return repeats+1;

        return -1;
    }
};