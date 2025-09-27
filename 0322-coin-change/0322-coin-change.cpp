class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int INF = 1e9;
      vector<vector<int>>t(n+1,vector<int>(amount+1,INF));

      //initialization 
      for(int i =0;i<=n;i++){
      t[i][0] = 0;
      }

      for(int i = 1;i<n+1;i++){
        for(int j =1;j<amount+1;j++){
            int notpick = t[i-1][j];
            int pick = INF;
            if(j >= coins[i-1]){
                pick = 1+ t[i][j-coins[i-1]];
            }
            t[i][j] = min(pick,notpick);
        }
      }
      return (t[n][amount] >= INF) ? -1 : t[n][amount];
    }
};