class Solution {
  public:
   
   bool solve(vector<int>& arr,int sum,int n ){
       
       if(sum==0) return true;
       if(n==0) return false;
           if(arr[n-1]<=sum){
               //to include or not include
              return  solve(arr,sum-arr[n-1],n-1) || solve(arr,sum,n-1);
           }
              return  solve(arr,sum,n-1);
   }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        return solve(arr,sum,n);
    }
};