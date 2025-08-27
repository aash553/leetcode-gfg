class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));

        // base case
        for(int j=0; j<=amount; j++) {
            dp[0][j] = 1e9; // cannot make sum with 0 coins
        }
        dp[0][0] = 0;

        // fill the second row (only first coin allowed)
        for(int j=0; j<=amount; j++) {
            if(j % coins[0] == 0) {
                dp[1][j] = j / coins[0];
            } else {
                dp[1][j] = 1e9;
            }
        }

        // rest of the table
        for(int i=2; i<n+1; i++) {
            for(int j=0; j<amount+1; j++) {
                if(coins[i-1] <= j) {
                    dp[i][j] = min(1 + dp[i][j - coins[i-1]], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][amount] >= 1e9 ? -1 : dp[n][amount];
    }
};
