class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0;
        int n = nums.size();
        int r = 0;
        int l = 0;
        int maxlen = 0;
        while(r<n){
            if(nums[r]==0) zeros++;

            if(zeros>k){
                if(nums[l] == 0)zeros--;
                l++;
            }
            maxlen = max(maxlen , r-l+1);
            r++;
        }
        return maxlen;
    }
};