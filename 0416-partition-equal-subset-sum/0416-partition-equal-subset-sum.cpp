class Solution {
public:

    vector<vector<int>>t;
    bool solve(vector<int>& nums,int i, int target){
        ///base condition 
        if(i >= nums.size() || target < 0) return false;
        if(target==0) return true;

        if(t[i][target]!=-1) return t[i][target];

      bool include = solve(nums,i+1,target-nums[i]);
      bool exclude = solve(nums,i+1,target);

        return t[i][target] = include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0;
        for(int n : nums) sum+=n;
        if(sum % 2 != 0) return false;
        int target = sum/2;
        t.assign(n+1,vector<int>(target+1,-1));
        return solve(nums,0,target);
    }
};