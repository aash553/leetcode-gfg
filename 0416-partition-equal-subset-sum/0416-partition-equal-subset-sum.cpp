class Solution {
public:

    vector<vector<int>>t;
    bool subset(vector<int>& nums,int i, int target){
        int n = nums.size();
        vector<vector<bool>>t(n+1,vector<bool>(target+1,false));
        for(int i =0;i<=n;i++){
           t[i][0] = true;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<target+1;j++){
                if(nums[i-1] <= j){
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][target];
    }

    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0;
        for(int n : nums) sum+=n;
        if(sum % 2 != 0) return false;
        int target = sum /2;
        return subset(nums,0,target);
    }
};