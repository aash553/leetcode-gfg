class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        

        int n = nums.size();
        int cnt = 0;

        unordered_map<int,int>prefix;
        int sum = 0;

        prefix[0]=1;

        for(int i=0;i<n;i++){
            sum+=nums[i];
        int rem = sum-goal;
        if(prefix.find(rem)!=prefix.end()){
        cnt+=prefix[rem];
        }
        prefix[sum]+=1;
        }
        return cnt;
    }
};