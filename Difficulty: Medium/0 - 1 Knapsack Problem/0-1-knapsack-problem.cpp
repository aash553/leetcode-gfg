class Solution {
  public:
  
  vector<vector<int>>t;
  
  int solve(int W , int n ,  vector<int> &val, vector<int> &wt){
      //base case 
      if(n == 0 || W == 0) return 0;
      if(t[n][W] != -1) return t[n][W];
     int include = 0;
     if(wt[n-1] <= W){
         include = val[n-1] + solve(W-wt[n-1],n-1,val,wt);
     }
     int exclude = solve(W,n-1,val,wt);
     
     return t[n][W] =  max(include , exclude);
  }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        t.assign(n+1,vector<int>(W+1,-1));
        return solve(W,n,val,wt);
    }
};