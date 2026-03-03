class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curr_max = nums[0];
        int maxi_max = nums[0];
        for(int i =1;i<n;i++){
            curr_max = max(nums[i],curr_max+nums[i]);
            maxi_max = max(maxi_max , curr_max);
        }
        return maxi_max;
    }
};