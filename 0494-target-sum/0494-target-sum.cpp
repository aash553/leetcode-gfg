class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
       int n = nums.size();
       int total = 0;
       for(int n: nums) total +=n;
       if((total+target)%2 != 0 || abs(target) > total) return 0;
       int point = (total + target)/2;
       //initalization
       vector<vector<int>>t(n+1,vector<int>(point+1,0));
       t[0][0] = 1;
       for(int i =1;i<=n;i++){
        if(nums[i-1] == 0){
            t[i][0] = 2 * t[i-1][0];
        }else{
            t[i][0] = t[i-1][0];
        }
       }
       for(int i =1;i<n+1;i++){
        for(int j=1;j<point+1;j++){
            if(nums[i-1] <= j){
                t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
            }else{
                t[i][j] = t[i-1][j];
            }
        }
       }
       return t[n][point];
    }
};