class Solution {
  public:
  
  vector<vector<int>>t;
  
  int solve(vector<int>& arr, int i , int target){
      //base condition 
      int n = arr.size();
      if (i == arr.size()) {
        return (target == 0) ? 1 : 0;
    }
      if (target < 0) return 0;
      
      if(t[i][target] != -1) return t[i][target];
      
      int include = solve(arr,i+1,target-arr[i]);
      int exclude = solve(arr,i+1,target);
      return t[i][target] =  include+exclude;
  }
  
  
  
    int countPartitions(vector<int>& arr, int d) {
        int total = 0;
        int n = arr.size();
        for(int t : arr) total += t;
        if((total+d) %2 != 0) return 0;
        int target = (total+d)/2;
        t.assign(n+1,vector<int>(target+1,-1));
        return solve(arr,0,target);
        
    }
};