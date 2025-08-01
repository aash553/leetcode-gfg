class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i =0;i<n;i++){
        int index = abs(nums[i])-1;
            if(nums[index]<0){
                ans.push_back(abs(nums[i]));
            }else{
            nums[index] *= -1;
            }
        }
        return ans;
    }
};