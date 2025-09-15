class Solution {
  public:
  
  void solve(vector<int>&arr , int i  ,int sum ,  vector<int>&ans){
      
      int n = arr.size();
      //base case 
      if(i==n){
          ans.push_back(sum);
          return;
      }
      
       solve(arr,i+1,arr[i]+sum,ans);
       solve(arr,i+1,sum,ans);
  }
  
  
    vector<int> subsetSums(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans;
        solve(arr,0,0,ans);
        return ans;
    }
};