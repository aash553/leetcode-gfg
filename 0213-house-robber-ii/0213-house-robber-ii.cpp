class Solution {
public:

    int solve(vector<int>&nums, int start , int end){
        int prev1 = 0 , prev2 = 0 ;
        for(int i = start ;i <= end ; i++){
            int pick = nums[i]+prev2;
            int skip = prev1;
            int curr = max(pick ,skip);
        prev2= prev1;
        prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        int ans1= solve(nums,0,n-2);
        int ans2 = solve(nums,1,n-1);

        return max(ans1,ans2);
    }
};