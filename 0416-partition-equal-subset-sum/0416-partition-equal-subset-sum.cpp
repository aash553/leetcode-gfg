class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums) sum += num;

        if(sum %2 != 0) return false;

        int target =sum/2;

        vector<vector<int>>t(n+1,vector<int>(target+1,-1));
       for(int i = 0;i<n;i++){
        t[i][0] = 1; //basically rteh sum is 0 and is the i row which denotes size of array so 
       }
       for(int j = 1; j <= target; j++) t[0][j] = 0;

       for(int i = 1;i<n+1 ;i++){
        for(int j= 1 ; j<target +1 ;j++){
            if(nums[i-1] <= j){
                t[i][j] = t[i-1][j] || t[i-1][j-nums[i-1]];
            }else{
                t[i][j] = t[i-1][j];
            }
        }
       }
       return t[n][target];
    }
};