class Solution {
public:


    void solve(int ind , int &n , int k , vector<vector<int>>&ans, vector<int>&ds){

        if(k==0){
            ans.push_back(ds);
            return;
        }

        if(ind>n) return;
        ds.push_back(ind);
        solve(ind+1,n,k-1,ans,ds);
        ds.pop_back();
        solve(ind+1,n,k,ans,ds);

    }

    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>>ans;
        vector<int>ds;

         solve(1,n,k,ans,ds);
        return ans;
    }
};