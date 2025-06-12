class Solution {
public:

    void fuz(int ind , int target , vector<int>&arr , vector<int> &ds , vector<vector<int>> &ans){
        if(ind == arr.size()){
            if(target == 0 ){
                ans.push_back(ds);
            }
            return;
        }
        //to pick
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            fuz(ind,target-arr[ind],arr,ds,ans);
            ds.pop_back();
        }
        //for not picking 
        fuz(ind+1,target,arr,ds,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;

        fuz(0,target,candidates,ds,ans);
        return ans;
    }
};