class Solution {
  public:
  
  void fun(int ind, int sum , vector<int>&arr, vector<int>&ds ,bool &found){

      if(sum==0){
          found = true;
          return;
      }
      for(int i=ind;i<arr.size();i++){
          if(i>ind && arr[i]==arr[i-1])continue;
          if(arr[i]>sum)break;
          
          ds.push_back(arr[i]);
          fun(i+1,sum-arr[i],arr,ds,found);
          ds.pop_back();
          
          if(found) return;
      }
  }
  
  
    bool isSubsetSum(vector<int>& arr, int sum) {
         sort(arr.begin(), arr.end());
        bool found = false;
        vector<int>ds;
        fun(0,sum,arr,ds,found);
        return found;
    }
};