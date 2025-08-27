// User function Template for C++

class Solution {
  public:
  vector<vector<int>>t;
  int solve(int i , int n ,vector<int> &price){
       if(n==0) return 0;
        if(i==0){
            return n * price[0];
        }
        
        if(t[i][n] != -1) return t[i][n];
        
        int notake = solve(i-1,n,price);
        int take = INT_MIN;
        if(i+1 <= n){
            take =price[i]+solve(i,n-(i+1),price);
        }
        return t[i][n] = max(take,notake);
  }
  
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        t.assign(n,vector<int>(n+1,-1));
        return solve(n-1,n,price);
    }
};