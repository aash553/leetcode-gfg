class Solution {
public:
    vector<int>t;
    int solve(vector<int>&nums  ,int n){
        //base case 
        if(n==0) return 0;
        if(n == 1) return nums[0];

        if(t[n] != -1) return t[n];
        int pick = nums[n-1]+ solve(nums,n-2);
        int notpick = solve(nums,n-1);

        return t[n] =  max(pick,notpick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        t.assign(n+1,-1);
        return solve(nums,n);
    }
};