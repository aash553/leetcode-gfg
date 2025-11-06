class Solution {
public:

    vector<int>t;
    int solve(vector<int>&cost , int n ){
        //base case 
        if(n == 0 || n == 1 ) return cost[n];
        if(t[n] != -1) return t[n];
        int one = solve(cost,n-1);
        int two = solve(cost,n-2);

        return t[n] =  cost[n] + min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        t.assign(n+1,-1);
        return min(solve(cost,n-1),solve(cost,n-2));
    }
};