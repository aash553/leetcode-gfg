class Solution {
public:

int solve(vector<int>nums , int k){
   unordered_map<int,int> mpp;

        int l =0;
        int r = 0;
        int n = nums.size();
        int cnt = 0;

        while(r<n){
            mpp[nums[r]]++;
        while(mpp.size()>k){
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0)
            mpp.erase(nums[l]);
            l++;
        }
        cnt += r-l+1;
        r=r+1;
        }
        return cnt;
}

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};