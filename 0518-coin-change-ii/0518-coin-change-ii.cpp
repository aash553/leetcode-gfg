class Solution {
public:

    vector<vector<int>>t;
    int solve(vector<int>&coins , int i , int amount){
        int n = coins.size();
        //base case 
        if(amount == 0) return 1 ;
        if(i>=n || amount<0) return 0;
        if(t[i][amount] != -1) return t[i][amount];
        //logic
        int include = solve(coins,i,amount-coins[i]);
        int exclude = solve(coins,i+1,amount);
        return t[i][amount] = include + exclude;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        t.assign(n+1,vector<int>(amount+1,-1));
        return solve(coins, 0 , amount);
    }
};