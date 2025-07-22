class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n  = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int maxi = INT_MIN;
        unordered_set<int> seen;
        while(r<n){
            while(seen.count(nums[r])){
                seen.erase(nums[l]);
                sum -= nums[l];
                l++;
            }
            seen.insert(nums[r]);
            sum += nums[r];
            maxi = max(maxi,sum);
            r++;
    }
    return maxi;
    }
};