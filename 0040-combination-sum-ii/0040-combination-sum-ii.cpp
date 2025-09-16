class Solution {
public:

    void solve(vector<int>& candidates, int i , int target , vector<int>&ds,vector<vector<int>>&ans){
        int n = candidates.size();
            if(target == 0){
                ans.push_back(ds);
            }
        for(int j = i; j<n;j++){
            if( j> i && candidates[j] == candidates[j-1])continue;
            if(candidates[j] > target) break;
            ds.push_back(candidates[j]);
            solve(candidates,j+1,target-candidates[j],ds,ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        solve(candidates , 0 , target , ds, ans);
        return ans;
    }
};