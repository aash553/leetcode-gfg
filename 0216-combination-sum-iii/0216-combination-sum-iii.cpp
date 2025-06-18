class Solution {
public:

    void solve(int ind, int n , int k , vector<int>&ds ,vector<vector<int>>&ans){
        if(ds.size()==k){
            if(n==0){
                ans.push_back(ds);
            }
                return;
            }
            for(int i=ind;i<=9;i++){
                if(i>n)break;
            ds.push_back(i);
            solve(i+1,n-i,k,ds,ans);
            ds.pop_back();
            }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        //k - is the size of the array which needs to be fixed
        // n - is the target 

        vector<vector<int>>ans;
        vector<int>ds;

        solve(1,n,k,ds,ans);
        return ans;
        
    }
};