class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        int cnt = 0;
        mpp[0]=1;
        int prefix = 0;
        for(int i=0;i<n;i++){
            prefix += nums[i];
        int rem = prefix - k;
        cnt += mpp[rem];
        mpp[prefix] +=1; 
    }
    return cnt;
    }
};