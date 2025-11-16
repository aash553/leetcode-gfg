class Solution {
public:

    vector<int>t;
    int solve(int n ){
        if(n <=1 ) return 1;
        if(t[n] !=-1) return t[n];
        int steps = solve(n-1) + solve(n-2);

        return t[n] = steps;
    }

    int climbStairs(int n) {
        t.assign(n+1,-1);
        return solve(n);
    }
};