class Solution {
public:

   
    int coinChange(vector<int>& coins, int amount) {
        //recursion 
        int n = coins.size();
       vector<vector<int>>t(n+1,vector<int>(amount+1,-1));
        
        t[0][0]=0;
        for(int i = 0 ;i<=n;i++){
            for(int j = 0 ;j<=amount;j++){
            t[0][j] = 1e9;
            t[i][0] = 0;
            }
        }

        for(int i = 1;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                int notpick = t[i-1][j];
                int pick = INT_MAX;
                if( j >= coins[i-1]){
                    pick = 1 + t[i][j-coins[i-1]];
                }
                t[i][j] = min(pick,notpick);
            }
        }
        return (t[n][amount] >= 1e9)  ? -1 : t[n][amount];
    }
};