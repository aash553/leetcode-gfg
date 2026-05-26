class Solution {
public:

    vector<vector<int>>threesum(vector<int>&nums , int start , int target){
        int n = nums.size();
        vector<vector<int>>res;
        for(int i = start;i<n;i++){
            if(i>start && nums[i] == nums[i-1]) continue;

            int j = i+1;
            int k = n-1;

            while(j<k){
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];

                if(sum == target){
                    vector<int>temp = {nums[i],nums[j],nums[k]};
                    res.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }else if(sum < target){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return res;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            long long newtarget = target - nums[i];

            vector<vector<int>>temp = threesum(nums,i+1,newtarget);

            for(auto triplets : temp){
                vector<int>quad;
                quad.push_back(nums[i]);
                for(auto x : triplets){
                    quad.push_back(x);
                }
                ans.push_back(quad);
            }
        }
        return ans;
    }
};