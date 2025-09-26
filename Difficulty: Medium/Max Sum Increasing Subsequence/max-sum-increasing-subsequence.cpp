class Solution {
  public:
  
  vector<vector<int>>t;
  int solve(vector<int>& arr, int i , int prevIndex){   
      
      int n = arr.size();
      if(i == n) return 0;
      if(t[i][prevIndex+1] != -1 ) return t[i][prevIndex+1];  
      
      int pick = 0;
      
      if(prevIndex == -1 || arr[i] > arr[prevIndex]){
          pick = arr[i] + solve(arr,i+1,i); 
      }
      
     int notpick =  solve(arr,i+1,prevIndex);
      return t[i][prevIndex+1] = max(pick,notpick);
  }
  
    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        t.assign(n,vector<int>(n+1,-1));  
        return solve(arr,0,-1); 
    }
};
