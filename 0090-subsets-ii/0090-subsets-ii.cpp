class Solution {
public:

    void solve(vector<int>& nums,int i ,vector<int>&ds , vector<vector<int>>&ans){
       ans.push_back(ds);
       for(int j =i ;j<nums.size();j++){
        if(j>i && nums[j] == nums[j-1]) continue;
        ds.push_back(nums[j]);
        solve(nums,j+1,ds,ans);
        ds.pop_back();
       }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
    solve(nums,0,ds,ans);
    return ans;
    }
};