class Solution {
public:

    vector<vector<int>>t;

    int solve(int i , int j , vector<int>& cuts){
        if(i>j) return 0;

        if(t[i][j] != -1) return t[i][j];
        int mini = INT_MAX;
        for(int ind = i;ind<=j;ind++){
            int cost = cuts[j+1] - cuts[i-1] + solve(i , ind-1 , cuts) + solve(ind+1,j,cuts); 
            mini = min(mini,cost);
        }
        return t[i][j] =  mini;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin() , 0);
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        t.assign(m,vector<int>(m,-1));
        return solve(1,m-2,cuts);
    }
};