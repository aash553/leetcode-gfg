class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix = 0;
        int cnt = 0;
        map<int,int>mpp;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            prefix += nums[i];
        
        int rem = prefix - k;
        cnt += mpp[rem];
        mpp[prefix] += 1;
        }
        return cnt;
    }
};