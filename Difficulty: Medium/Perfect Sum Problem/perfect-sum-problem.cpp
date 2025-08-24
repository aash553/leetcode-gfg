class Solution {
  public:
  
  vector<vector<int>>t;
    int solve(vector<int>&arr, int i , int target ){
        int n = arr.size();
        //base condition
       if (i == arr.size()) {
    return (target == 0) ? 1 : 0;
        }
        
        if(t[i][target] != -1) return t[i][target];
        
        
        int include=0; 
        if(arr[i]<=target){
         include = solve(arr,i+1,target-arr[i]);
        }
       int exclude = solve(arr,i+1,target);
        return t[i][target] = include + exclude;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        //recusrion  first then  wil; try memoization 
        int n = arr.size();
        t.assign(n+1,vector<int>(target+1,-1));
       return solve(arr,0,target);
    }
};