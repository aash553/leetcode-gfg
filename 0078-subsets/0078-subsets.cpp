class Solution {
public:

    void fun(int ind, vector<int>&arr , vector<int>&ds ,int n, vector<vector<int>>&ans){
        if(ind == n){
            ans.push_back(ds);
            return;
        }
        //if picking the ds 
        ds.push_back(arr[ind]);
        fun(ind+1,arr,ds,n,ans);
        ds.pop_back();

        //if not picking the element in the that particular index
        fun(ind+1,arr,ds,n,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>ds;
        fun(0,nums,ds,n,ans);
        return ans;
    }
};