class Solution {
public:

    void solve(vector<int>& nums , int i , int sum ,   vector<int>&ds, vector<vector<int>>&ans){
        int n = nums.size();
        //bsae case 
        if(i==n){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        solve(nums,i+1,nums[i]+sum,ds,ans);
        ds.pop_back();
        solve(nums,i+1,sum,ds,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(nums,0,0,ds,ans);
        return ans;
    }
};