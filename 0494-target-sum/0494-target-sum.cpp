class Solution {
public:

    int solve(vector<int>& nums, int i , int point){
        int n = nums.size();
        //base case 
        if(i==n){
            return (point==0) ? 1 :0;
        }

        int include = solve(nums,i+1,point-nums[i]);
        int exclude = solve(nums,i+1,point);

        return include + exclude;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int total = 0;
        for(int n : nums) total += n;
        if((total+target) %2 !=0) return 0;
        int point = (total + target)/2;
        return solve(nums,0,point);
    }
};