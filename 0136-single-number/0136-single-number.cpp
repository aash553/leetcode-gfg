class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xr =0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            xr = xr ^  nums[i] ;
        }
        return xr;
    }
};