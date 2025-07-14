class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int windowsum = 0;
        int minlen = INT_MAX;
        for(int right =0; right<nums.size();right++){
            windowsum+= nums[right];
        while(windowsum>=target){
            minlen = min(minlen , right-left+1);
            windowsum -= nums[left];
            left++;
        }
        }
        return (minlen==INT_MAX) ? 0 : minlen;
    }
};