class Solution {
public:

    void recur(int index , set<vector<int>>& ss, vector<int>&nums){
        if(index==nums.size()){
            ss.insert(nums);
            return;
        }

        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            recur(index+1,ss,nums);
            swap(nums[index],nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ss;
       // vector<vector<int>>ans;
        recur(0,ss,nums);
        return vector<vector<int>>(ss.begin(), ss.end());
    }
};