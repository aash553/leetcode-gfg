class Solution {
public:

    vector<vector<int>>t;
    int solve(vector<int>&coins , int i , int amount){

        int n = coins.size();
        if(i == n) return 1e9;
        if(amount == 0 ) return 0 ;
        if(amount < 0) return 1e9;

        if(t[i][amount] != -1) return t[i][amount];

        int include = 1 + solve(coins , i , amount-coins[i]);
        int exclude = solve(coins,i+1,amount);

        return t[i][amount] = min(include , exclude);


    }

    int coinChange(vector<int>& coins, int amount) {
        //recursion 
        int n = coins.size();
        t.assign(n+1,vector<int>(amount+1,-1));
        int ans =  solve(coins , 0 , amount);
        return (ans >= 1e9) ? -1 : ans;
    }
};