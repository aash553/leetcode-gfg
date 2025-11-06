class Solution {
  public:
  
  bool solve(vector<int>&arr ,int n , int sum ){
      if(sum == 0) return true;
      if(n==0) return false;
      
      if(arr[n-1] <= sum){
      return solve(arr,n-1,sum-arr[n-1]) || solve(arr,n-1,sum);
      }
      return solve(arr,n-1,sum);
  }
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        //using recursion 
        int n = arr.size();
        return solve(arr,n,sum);
    }
};