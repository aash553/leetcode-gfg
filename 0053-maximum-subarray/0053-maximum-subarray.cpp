class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curr_sum = nums[0];
        int maxi_sum = nums[0];

        for(int i =1;i<n;i++){
            curr_sum = max(nums[i],curr_sum+nums[i]);
            maxi_sum = max(maxi_sum,curr_sum);
        }
        return maxi_sum;
    }
};