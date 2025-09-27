class Solution {
public:
    vector<vector<int>>t;
    bool solve(vector<int>&nums , int i , int target){
        //base case 
        int n = nums.size();
        if( target == 0) return true;
        if ( i >= n || target < 0 ) return false;

        if(t[i][target] != -1) return t[i][target];

        if(solve(nums,i+1,target-nums[i])) return true;
        if(solve(nums,i+1,target)) return true;

        return t[i][target] =  false;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums) sum += num;

        if(sum %2 != 0) return false;

        int target =sum/2;

        t.assign(n+1,vector<int>(target+1,-1));

        return solve(nums,0,target);
    }
};