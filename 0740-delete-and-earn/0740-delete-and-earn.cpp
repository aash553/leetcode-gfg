class Solution {
public:
    vector<int>t;
    int solve(vector<int>&points , int i){
        if(i == 0 ) return 0;
        if(i == 1) return points[1];
        if(t[i] != -1) return t[i];
        int pick = points[i] + solve(points,i-2);
        int notpick = solve(points, i-1);

        return t[i]= max(pick,notpick);
    }

    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int>points(maxi+1,0);

        for(int x : nums){
            points[x] += x;
        }
        t.assign(maxi+1 , -1);
        return solve(points, maxi);
    }
};