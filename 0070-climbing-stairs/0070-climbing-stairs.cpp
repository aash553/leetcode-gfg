class Solution {
public:

    vector<int>t;
    int solve(int n){
        //base case 
        if(n==0 || n==1 ) return 1;
        if(t[n] != -1) return t[n];
        return t[n] =  solve(n-1) + solve(n-2);
    }

    int climbStairs(int n) {
        t.assign(n+1,-1);
        return solve(n);
    }
};