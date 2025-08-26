class Solution {
public:

    vector<vector<int>>t;
    int solve(vector<int>& nums, int i , int point){
        int n = nums.size();
        //base case 
        if(i==n){
            return (point==0) ? 1 :0;
        }

        if (point < 0) return 0;

        if(t[i][point] != -1) return t[i][point];
         int include = 0;
        if (nums[i] <= point) {
            include = solve(nums, i+1, point - nums[i]);
        }
        int exclude = solve(nums,i+1,point);

        return t[i][point] = include + exclude;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int total = 0;
        for(int n : nums) total += n;
        if((total+target) %2 !=0 || abs(target) > total) return 0;
        int point = (total + target)/2;
        t.assign(n+1,vector<int>(point+1,-1));
        return solve(nums,0,point);
    }
};