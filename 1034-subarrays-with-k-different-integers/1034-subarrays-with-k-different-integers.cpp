class Solution {
public:

    int solve(vector<int>&nums, int k ){
          int n = nums.size();
       // unordered_map<int,int>mpp;
       int freq[100005]={0};
        int l=0;
        int r=0;
        int cnt = 0;
        int discnt=0;
        while(r<n){
            //mpp[nums[r]]++;
            if(freq[nums[r]]==0){
                discnt++;
            }
            freq[nums[r]]++;
            while(discnt>k){
                freq[nums[l]]--;
                if(freq[nums[l]]==0){
                discnt--;
                }
            l++;
            }

            cnt = cnt+(r-l+1);
            r=r+1;

        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};