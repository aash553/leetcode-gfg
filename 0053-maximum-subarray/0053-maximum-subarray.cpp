class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_max = nums[0];
        int maxi_max = nums[0];
        for(int i =1;i<nums.size();i++){
            curr_max = max(nums[i],curr_max+nums[i]);
            maxi_max= max(curr_max,maxi_max);
        }
        return maxi_max;
    }
};