class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        long long sum = 0 ;
        long long  maxi = LLONG_MIN;
        int l =0;
        for(int r =0 ;r<nums.size();r++){
            mpp[nums[r]]++;
            sum += nums[r];
            if(r-l+1 > k){
            mpp[nums[l]]--;
            sum -= nums[l];
            if(mpp[nums[l]] == 0)
            mpp.erase(nums[l]);
            l++;
        }
        if(r-l+1 == k && mpp.size() == k){
            maxi = max(maxi,sum);
        }
        }
         return (maxi == LLONG_MIN) ? 0 : maxi;
    }
};