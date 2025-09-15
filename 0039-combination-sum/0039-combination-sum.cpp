class Solution {
public:

    void solve(vector<int>& candidates , int i ,vector<int>&ds , int target , vector<vector<int>>&ans){
        int n = candidates.size();
        if(i==n){
            if(target == 0 ){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[i] <= target){
            ds.push_back(candidates[i]);
            solve(candidates , i , ds ,target-candidates[i],ans);
            ds.pop_back();
        }
        solve(candidates,i+1,ds,target,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(candidates,0,ds,target,ans);
        return ans;

    }
};