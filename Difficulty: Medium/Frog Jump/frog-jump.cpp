class Solution {
  public:
  
    int f(int ind ,vector<int>& height, vector<int>&dp){
        
        if(ind==0) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        int left = f(ind-1,height,dp) + abs(height[ind]-height[ind-1]);
        int right = INT_MAX;
        
        if(ind>1)right = f(ind-2,height,dp) + abs(height[ind]-height[ind-2]);
        
        return dp[ind]=min(right,left);
    }
  
    int minCost(vector<int>& height) {
        
        int n = height.size();
        vector<int>dp(n+1,-1);
        return f(n-1,height,dp);
    }
};