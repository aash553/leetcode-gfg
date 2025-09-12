class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curr_profit = nums[0];
        int max_profit = nums[0];

        for(int i=1;i<n;i++){
            curr_profit = max(nums[i],curr_profit+nums[i]);
            max_profit = max(curr_profit,max_profit);
        }

        return max_profit;
    }
};