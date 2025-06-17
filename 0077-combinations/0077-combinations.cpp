class Solution {
public:

    void help(int ind , int &n, int k , vector<int>&ds, vector<vector<int>>&ans){
        if(k==0){
            ans.push_back(ds);
            return;
        }

        if(ind>n) return;
        ds.push_back(ind);
        
        help(ind+1,n,k-1,ds,ans);
        ds.pop_back();

        help(ind+1,n,k,ds,ans);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>ds;
        help(1,n,k,ds,ans);
        return ans;
    }
};