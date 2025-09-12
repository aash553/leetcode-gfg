class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        for(int i  = 0;i< nums.size();i++){
            mpp[nums[i]]++;
        }
        int ans = 0;
        for(auto it : mpp){
            int num = it.first;
            int freq = it.second;
            if( freq > n/2){
                ans = it.first;
            }
        }
        return ans;
    }
};