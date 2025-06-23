class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        unordered_set<int>seen;
        
        for(int i =0;i<arr.size();i++){
            int compli = target - arr[i];
            if(seen.count(compli)) return true;
            seen.insert(arr[i]);
        }
        return false;
    }
};